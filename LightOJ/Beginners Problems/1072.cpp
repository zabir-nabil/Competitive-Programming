#include<stdio.h>
#include<math.h>
int main()
{

    int tc = 0 ;
    scanf("%d",&tc);
    int loop, n ;
    double R,intermediateP;
    double pi_times_2 = 2*acos(-1);

    for(loop = 0; loop < tc ; loop++)
    {
        scanf("%lf %d",&R,&n);
        intermediateP = sqrt(2*(1-cos(pi_times_2/n)));
        printf("Case %d: %.9lf\n",loop+1,intermediateP*R/(2+intermediateP));
    }






    return 0;
}
