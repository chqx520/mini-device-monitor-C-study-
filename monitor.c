#include <stdint.h>
#include <stdlib.h>
#include "monitor.h"

static const double TEMP_MIN = 20.00;
static const double TEMP_MAX = 40.00;


double *generate_samples(size_t len)
{
    if (len == 0 || len > SIZE_MAX / sizeof(double))
    {
        return NULL;
    }

    double *samples = malloc(len * sizeof *samples);
    if (samples == NULL)
    {
        return NULL;
    }

    for (size_t i = 0; i < len; i++)
    {
        samples[i] = rand() % 31 + 15;
    }

    return samples; 
}

//计算数据的平均值和超出范围的值的个数,失败返回0，成功返回1
int calculate(const double arr[], size_t len, double *pave, size_t *pabnormal)
{
    if (len == 0 || arr == NULL || pave == NULL || pabnormal == NULL)
    {
        return 0;
    }

    size_t count_ab = 0;
    double sum = 0;
    for (size_t i = 0; i < len; i++)
    {
        if (arr[i] < TEMP_MIN || arr[i] > TEMP_MAX)
        {
            count_ab++;
        }
        sum += arr[i];
    }
    *pave = sum / (double)len;
    *pabnormal = count_ab;
    return 1;
}

//找出数据最大值,失败返回0，成功返回1
int find_max(const double arr[], size_t len, double *pmax)
{
    if (len == 0 || arr == NULL || pmax == NULL)
    {
        return 0;
    }

    double temp = arr[0];
    for (size_t i = 1; i < len; i++)
    {
        if (temp < arr[i]){
            temp = arr[i];
        }
    }
    *pmax = temp;
    return 1;
}

//找出数据最小值,失败返回0，成功返回1
int find_min(const double arr[], size_t len, double *pmin)
{
    if (len == 0 || arr == NULL || pmin == NULL)
    {
        return 0;
    }

    double temp = arr[0];
    for (size_t i = 1; i < len; i++)
    {
        if (temp > arr[i]){
            temp = arr[i];
        }
    }
    *pmin = temp;
    return 1;
}