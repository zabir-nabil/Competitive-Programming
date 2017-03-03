
#include <stdio.h>

double arr[12];
int main()
{
    double sum =0.00;
   int i;
   for(i=0;i<12;i++)
    {

        scanf("%lf",&arr[i]);
        sum+=arr[i];
    }
    printf("$%.2f\n",sum/12.00);


    return 0;
}
