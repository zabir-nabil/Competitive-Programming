//C++ 	0.000 	1088  Accepted
#include<stdio.h>
int main()
{
    int tc=0;
    scanf("%d",&tc);
    for(int loop=1;loop<=tc;loop++)
    {
     int a,b;
     scanf("%d %d",&a,&b);
     int c= a+b;
        printf("Case %d: %d\n",loop,c);
    }
 
    return 0;
 
}