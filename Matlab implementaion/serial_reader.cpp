#include <iostream>
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>
#include <cstring>
#include <string>
#include <sys/ioctl.h>
#include <linux/serial.h>
#include "serial_reader.hpp"

// Global state variables
int serial_port = -1;
std::string serial_buffer = ""; // Persistent buffer for incoming fragments

void init_serial() {
    // 1. Open Port
    const char* port_name = "/dev/ttyAMA3";
    serial_port = open(port_name, O_RDWR | O_NOCTTY | O_NDELAY);

    if (serial_port < 0) {
        // Use standard error for Simulink diagnostics
        std::cerr << "Error opening serial port: " << port_name << std::endl;
        return;
    }

    // 2. Configure 921600 Baud (Your exact settings)
    struct termios tty;
    if(tcgetattr(serial_port, &tty) != 0) return;

    cfsetospeed(&tty, B921600);
    cfsetispeed(&tty, B921600);

    tty.c_cflag &= ~PARENB; // No Parity
    tty.c_cflag &= ~CSTOPB; // 1 Stop bit
    tty.c_cflag &= ~CSIZE;
    tty.c_cflag |= CS8;     // 8 bits
    tty.c_cflag |= CREAD | CLOCAL;
    
    // Raw mode setup
    tty.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG); 
    tty.c_iflag &= ~(IXON | IXOFF | IXANY);
    tty.c_iflag &= ~(IGNBRK | BRKINT | PARMRK | ISTRIP | INLCR | IGNCR | ICRNL);
    tty.c_oflag &= ~OPOST;
    
    tcsetattr(serial_port, TCSANOW, &tty);
    tcflush(serial_port, TCIFLUSH);
}

int read_serial_data(double* t, double* w, double* l) {
    if (serial_port < 0) return 0;

    char temp_buf[1024];
    
    // 1. Read available bytes (non-blocking)
    int n = read(serial_port, temp_buf, sizeof(temp_buf));
    
    if (n > 0) {
        // Append raw bytes to our persistent string buffer
        serial_buffer.append(temp_buf, n);
    }

    // 2. Look for the LAST complete line to ensure we use the freshest data
    // We search for the last newline character
    size_t last_newline = serial_buffer.rfind('\n');

    if (last_newline != std::string::npos) {
        // Find the start of that line (the newline before the last one)
        size_t start_of_line = serial_buffer.rfind('\n', last_newline - 1);
        
        std::string line;
        if (start_of_line == std::string::npos) {
            // Only one line in buffer, take from start
            line = serial_buffer.substr(0, last_newline);
        } else {
            // Take the segment between the two newlines
            line = serial_buffer.substr(start_of_line + 1, last_newline - start_of_line - 1);
        }

        // 3. Parse the line
        unsigned long esp_time_raw;
        double omega_raw, load_raw;
        
        // Matches your format: "%lu,%lf,%lf"
        if (sscanf(line.c_str(), "%lu,%lf,%lf", &esp_time_raw, &omega_raw, &load_raw) == 3) {
            *t = (double)esp_time_raw;
            *w = omega_raw;
            load_raw = load_raw*142.5*0.0083+0.0171;
            *l = load_raw;
            
            // 4. Cleanup: Remove everything up to the processed line to keep buffer small
            serial_buffer.erase(0, last_newline + 1);
            return 1; // Success
        }
        
        // If parse failed, still clear buffer to prevent overflow
        serial_buffer.erase(0, last_newline + 1);
    }
    
    return 0; // No new complete line found yet
}

void close_serial() {
    if (serial_port >= 0) {
        close(serial_port);
        serial_port = -1;
    }
}