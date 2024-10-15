#include <stdio.h>
float user_inputf()
{
    float num;
    short flag = 0;
    while (flag != 1)
    {
        if (scanf("%f", &num) == 1 & num > 0)
        {
            flag = 1;
        }
        else
        {
            printf("try again\n");
            fflush(stdin);
        }
    }
    return num;
}
float fct(float num)
{
    float fact = 1;
    for (int i = 1; i <= num; i++)
    {
        fact = fact * i;
    }
    return fact;
}
int main()
{
    float E = user_inputf();
    short flag = 0;
    int times = 1;
    float *S_the_first;
    float S_for_the_first = -100;
    S_the_first = &S_for_the_first;
    while (flag != 1)
    {
        float S = 0;
        for (int n = 1; n <= times; n++)
        {
            float S1 = 1 / fct(n);
            S = S + S1;
        }
        if (S - *S_the_first < E)
        {
            flag = 1;
        }
        *S_the_first = S;
        times++;
    }
    printf("%f", *S_the_first);
}