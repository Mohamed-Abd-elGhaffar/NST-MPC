#ifndef CSV_LOGGER_H_
#define CSV_LOGGER_H_

#ifdef __cplusplus
extern "C" {
#endif

// Logs a full row of data: Time, Omega, Load, 7 Gates, 9 Aggs
void fast_log_full_row(const double* gateS, const double* aggS, const double* Pg, const double* Pa);

#ifdef __cplusplus
}
#endif

#endif