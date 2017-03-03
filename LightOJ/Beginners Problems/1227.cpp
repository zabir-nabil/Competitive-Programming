#include<stdio.h>
int main()
{
    int tc;
    int n,P,Q;
    scanf("%d",&tc);
    int new_mass[31],sum_mass,lop2;
    for(int loop=1; loop<=tc; loop++)
    {
        scanf("%d %d %d",&n,&P,&Q);
        sum_mass = 0;

        for(int lop4 = 0 ; lop4 < 31 ; lop4++)
            new_mass[lop4] = 999999 ; // aliasing

        for(int lop3 = 0 ; lop3 < n ; lop3++)
            scanf("%d",&new_mass[lop3]); //simulation ..don't need all mass es till nth

        for(lop2 = 1 ; lop2 <= P ; lop2++)
        {

            sum_mass += new_mass[lop2-1];

            if(sum_mass>Q)
            {
                break;
            }
            if(lop2>n)
            {
                break;
            }
        }
        printf("Case %d: %d\n",loop,lop2-1);

    }


    return 0;
}

