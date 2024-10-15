#include <stdio.h>
#include <math.h>
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


int main(){
    float a = user_inputf();
    float b = user_inputf();
    float E = user_inputf();
    short flag = 0;
    int num_of_gaps = 2;
    float S_for_the_first = -100;
    float *S_step_minus_1;
    S_step_minus_1 = &S_for_the_first;
    while (flag != 1){
        float S = 0;
        for (float x = a; x < b; x = x + (b - a) / num_of_gaps){
            float x1 = x;
            float x2 = x + ((b - a) / num_of_gaps)/2;
            float x3 = x + (b - a) / num_of_gaps;
            float S1 = (x2-x1)/3*(logf(x1) + 4*logf(x2) + logf(x3));
            S = S + S1;
        }     
        if ((S - *S_step_minus_1) < E){
            flag = 1;
        }
        *S_step_minus_1 = S;
        num_of_gaps = num_of_gaps*2;
    }
    printf("%f\n", *S_step_minus_1);
    return 0;
}