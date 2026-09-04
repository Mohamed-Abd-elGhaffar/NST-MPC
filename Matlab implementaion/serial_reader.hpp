#ifndef SERIAL_READER_H_
#define SERIAL_READER_H_

#ifdef __cplusplus
extern "C" {
#endif

// Initialize the serial port settings
void init_serial();

// Read the latest available data
// Returns 1 if new data was found, 0 otherwise
// Updates the variables pointed to by t, w, and l
int read_serial_data(double* t, double* w, double* l);

// Clean up
void close_serial();

#ifdef __cplusplus
}
#endif

#endif