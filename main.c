#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "monitor.h"

static void show_menu(void);
static void show_data(const double arr[], size_t len);
static void show_report(const double arr[], size_t len);

int main(void)
{
    const double tem[] =  { 25.5, 26.1, 27.3, 28.0, 41.2,
                            29.5, 30.1, 19.8, 27.7, 28.4 };

    size_t ltem = sizeof tem / sizeof tem[0]; 
    const double *current = tem;
    double *generate = NULL;

    int num;
    do
    {
        show_menu();
        char get[10];
        fgets(get, 10, stdin);
        char *end;
        num = strtol(get, &end, 10);

        if (isalpha(*end))
        {
            printf("Please enter the right number!\n\n\n");
            continue;
        }

        if (num == 0)
        {
            printf("Goodbye!\n");
            break;
        }
        else if (num == 1){ show_data(current, ltem);}
        else if (num == 2){ show_report(current, ltem);}
        else if (num == 3){ 
                            char line[10];
                            printf("How many samples: ");
                            fgets(line, 10, stdin);
                            char *end;
                            long count = strtol(line, &end, 10);
                            if (isalpha(*end))
                            {
                                printf("warning\n");
                                continue;
                            }

                            double *temp = generate_samples(count);
                            if (temp != NULL)
                            {
                               printf("数据更新成功\n\n");
                               current = generate = temp;
                               ltem = count;
                            }
                            else
                            {
                               printf("REEOR\n");
                            }
                          }
        else
        {
            printf("Please enter the right number!\n\n\n");
            continue;
        }
    } while (1);

    free(generate);
    return 0;
}


//显示主菜单
static void show_menu(void)
{
    printf("\033[32m=== Mini Device Monitor v0.2 ===\n\n");
    printf("1. View temperature data\n");
    printf("2. Analyze temperature data\n");
    printf("3. 生成新数据\n");
    printf("0. Exit\n\n");
    printf("Select >\033[0m ");
}

//显示当前的数据
static void show_data(const double arr[], size_t len)
{
    if (len == 0 || arr == NULL)
    {
        return;
    }

    for (size_t i = 0; i < len; i++)
    {
        printf("%02zu: %.2f C\n", i+1, arr[i]);
    }
    printf("\n\n");
    return;
}

//显示数据的个数，平均值，最大值，最小值，错误个数
static void show_report(const double arr[], size_t len)
{
    double ave;
    size_t abnormal;
    double tmax, tmin;

    int c_cal = calculate(arr, len, &ave, &abnormal);
    int c_max = find_max(arr, len, &tmax);
    int c_min = find_min(arr, len, &tmin);

    if (c_cal == 1 && c_max == 1 && c_min == 1)
    {
        printf("Samples  : %zu   \n", len);
        printf("Average  : %.2f C\n", ave );
        printf("Maximum  : %.2f C\n", tmax);
        printf("Minimum  : %.2f C\n", tmin);
        printf("Abnormal : %zu   \n", abnormal);
        if (abnormal) printf("Status   : WARNING\n\n\n");
        else          printf("Status   : NORMAL \n\n\n");
    }
    else
    {
        printf("Error: Unable to analyze temperature data.\n");
    }
}


