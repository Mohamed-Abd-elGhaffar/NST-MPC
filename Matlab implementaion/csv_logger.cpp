#include <cstdio>
#include <mutex>
#include "csv_logger.hpp"

// Global file handle and mutex
FILE *log_file = nullptr;
std::mutex log_mutex;

void log_full_row(const double *gateS, const double *aggS)
{
    std::lock_guard<std::mutex> guard(log_mutex);
}

static void write_header_if_empty(FILE *f)
{
    fseek(f, 0, SEEK_END);
    if (ftell(f) == 0)
    {
        for (int i = 1; i <= 6; ++i)
            fprintf(f, "G%d,", i);

        for (int i = 1; i <= 9; ++i)
            fprintf(f, "A%d,", i);

        for (int i = 1; i <= 36; ++i)
            fprintf(f, "Pg%d,", i);

        for (int i = 1; i <= 81; ++i)
        {
            fprintf(f, "Pa%d", i);
            if (i < 81)
                fprintf(f, ",");
        }

        fprintf(f, "\n");
    }
}

// Backwards-compatible wrapper: existing callers with two arrays keep working.

// New overload: optionally accept flattened matrices
void log_full_row(const double *gateS, const double *aggS, const double *pg, const double *pa)
{
    std::lock_guard<std::mutex> guard(log_mutex);

    // 1. Open File if not open
    if (log_file == nullptr)
    {
        log_file = fopen("sim_data.csv", "a"); // Append mode

        // 2. Write Header if file is empty
        if (log_file != nullptr)
        {
            write_header_if_empty(log_file);
        }
    }

    if (log_file == nullptr)
        return;

    // 4. Print 7 Gate States
    for (int i = 0; i < 6; i++)
    {
        fprintf(log_file, "%.2f,", gateS[i]);
    }

    // 5. Print 9 Agg States
    for (int i = 0; i < 9; i++)
    {
        fprintf(log_file, "%.2f,", aggS[i]);
    }

    // 6. Print Pg flattened 7x7 matrix (49 values) if provided
    if (pg)
    {
        for (int i = 0; i < 36; ++i)
            fprintf(log_file, "%.6g,", pg[i]);
    }

    // 7. Print Pa flattened 9x9 matrix (81 values) if provided
    if (pa)
    {
        for (int i = 0; i < 81; ++i)
        {
            fprintf(log_file, "%.6g", pa[i]);
            if (i < 80)
                fprintf(log_file, ",");
        }
    }

    fprintf(log_file, "\n");
    fflush(log_file); // Ensure data is saved immediately
}
