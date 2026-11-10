#include <stdio.h>

int calculate(const double arr[], size_t len, double *pave);
double max(const double arr[], size_t len);
double min(const double arr[], size_t len);

int main(void)
{
    const double tem[] =  { 20.0, 40.0, 30.00, 40.0 };
    double ave;
    size_t ltem = sizeof tem / sizeof tem[0]; 

    int warn = calculate(tem, ltem, &ave);
    double tmax = max(tem, ltem);
    double tmin = min(tem, ltem);

    printf("Samples  : %zu   \n", ltem);
    printf("Average  : %.2f C\n", ave );
    printf("Maximum  : %.2f C\n", tmax);
    printf("Minimum  : %.2f C\n", tmin);
    printf("Abnormal : %d    \n", warn);
    if (warn) printf("Status   : WARNING\n");
    else      printf("Status   : NORMAL \n");

    return 0;
}

int calculate(const double arr[], size_t len, double *pave)
{
    int count_ab = 0;
    double sum = 0;
    for (size_t i = 0; i < len; i++)
    {
        if (arr[i] < 20.00 || arr[i] > 40.00)
            count_ab++;

        sum += arr[i];
    }
    *pave = sum / len;
    return count_ab;
}
double max(const double arr[], size_t len)
{
    double temp = arr[0];
    for (size_t i = 1; i < len; i++)
    {
        if (temp < arr[i]){
            temp = arr[i];
        }
    }
    return temp;
}
double min(const double arr[], size_t len)
{
    double temp = arr[0];
    for (size_t i = 1; i < len; i++)
    {
        if (temp > arr[i]){
            temp = arr[i];
        }
    }
    return temp;
}