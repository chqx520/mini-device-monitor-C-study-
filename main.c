#include <stdio.h>

static const double TEMP_MIN = 20.00;
static const double TEMP_MAX = 40.00;

void show_menu(void);
void show_data(const double arr[], size_t len);
void show_report(const double arr[], size_t len);

int calculate(const double arr[], size_t len, double *pave, size_t *pabnormal);
int find_max(const double arr[], size_t len, double *pmax);
int find_min(const double arr[], size_t len, double *pmin);
void clear_input_line(void);

int main(void)
{
    const double tem[] =  { 25.5, 26.1, 27.3, 28.0, 41.2,
                            29.5, 30.1, 19.8, 27.7, 28.4 };
    size_t ltem = sizeof tem / sizeof tem[0]; 

    int num;
    int n;
    do
    {
        show_menu();
        n = scanf("%d", &num);
        if (n == EOF)
        {
            break;
        }
        clear_input_line();

        if (n != 1)
        {
            printf("Please enter the right number!\n\n\n");
            continue;
        }

        if (num == 0)
        {
            printf("Goodbye!\n");
            break;
        }
        else if (num == 1) { show_data(tem, ltem);}
        else if (num == 2) { show_report(tem, ltem);}
        else
        {
            printf("Please enter the right number!\n\n\n");
            continue;
        }
    } while (1);

    return 0;
}


//显示主菜单
void show_menu(void)
{
    printf("=== Mini Device Monitor v0.2 ===\n\n");
    printf("1. View temperature data\n");
    printf("2. Analyze temperature data\n");
    printf("0. Exit\n\n");
    printf("Select > ");
}

//显示当前的数据
void show_data(const double arr[], size_t len)
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
void show_report(const double arr[], size_t len)
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

//清空缓冲区
void clear_input_line(void)
{
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF)
    {

    }
}


