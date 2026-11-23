#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include "monitor.h"

int main(void)
{
    const double tem1[] = {19, 20, 30, 40, 41};
    double average;
    size_t abnormal;

    int result1 = calculate(tem1, 5, &average, &abnormal);
    assert(result1 == 1);
    assert(average == 30.0);
    assert(abnormal == 2);

    const double tem2[] = {30.0, 41.0, 19.0};
    double max;
    double min;

    int result2 = find_max(tem2, 3, &max);
    assert(result2 == 1);
    int result3 = find_min(tem2, 3, &min);
    assert(result3 == 1);



    double *samples = malloc(3 * sizeof *samples);
    assert(samples != NULL);
    samples[0] = 18.0;
    samples[1] = 27.0;
    samples[2] = 39.0;

    int result4 = calculate(samples, 3, &average, &abnormal);
    assert(result4 == 1);
    assert(average == 28.0);
    assert(abnormal == 1);

    double *pgs = generate_samples(5);
    assert(pgs != NULL);
    for (int i = 0; i < 5; i++)
    {
        assert(pgs[i] >= 15 && pgs[i] <= 45);
    }
    free(pgs);

    return 0;
}