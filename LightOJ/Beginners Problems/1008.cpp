//C++ 	0.000 	1700   Accepted 
#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;
typedef unsigned long long ull;
int main()
{
    int tc;
    scanf("%d",&tc);
    for(int loop = 1; loop<=tc; loop++)
    {
        ull t;
        scanf("%llu",&t);
        double t_prime = sqrt(t);
        ull t_pr_prime = ceil(t_prime);
        ull n = t_pr_prime;
        ull level_val = ( (t_pr_prime)*(t_pr_prime) + (t_pr_prime - 1)*(t_pr_prime - 1) + 1 )/2;
        ull level_max = (t_pr_prime)*(t_pr_prime);
        ull level_min = (t_pr_prime - 1)*(t_pr_prime - 1) + 1 ;
        if(n%2==0)
        {
            if(t<level_val)
                printf("Case %d: %llu %llu\n",loop,t-level_min+1,n);
            if(t>level_val)
                printf("Case %d: %llu %llu\n",loop,n,level_max-t+1);

            if(t==level_val)
                printf("Case %d: %llu %llu\n",loop,n,n);


        }
        else
        {
            if(t<level_val)
                printf("Case %d: %llu %llu\n",loop,n,t-level_min+1);
            if(t>level_val)
                printf("Case %d: %llu %llu\n",loop,level_max-t+1,n);

            if(t==level_val)
                printf("Case %d: %llu %llu\n",loop,n,n);


        }
    }
    return 0;
}
