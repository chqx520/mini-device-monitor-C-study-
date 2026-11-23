#ifndef MONITOR_H
#define MONITOR_H
#include <stddef.h>

double *generate_samples(size_t len);
int calculate(const double arr[], size_t len, double *pave, size_t *pabnormal);
int find_max(const double arr[], size_t len, double *pmax);
int find_min(const double arr[], size_t len, double *pmin);

#endif