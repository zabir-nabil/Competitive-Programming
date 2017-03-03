#include<stdio.h>
#include<math.h>
int main()
{
 
int tc = 0;
double rad ,rad_sqr;
scanf("%d",&tc);
 
for(int loop = 0;loop<tc;loop++)
{
   
    scanf("%lf",&rad);
rad_sqr = rad*rad ;
 
    printf("Case %d: %.2lf\n",loop+1,4*(rad_sqr) - 2*acos(0.00)*(rad_sqr) + .000000001f);
}
    return 0;
}