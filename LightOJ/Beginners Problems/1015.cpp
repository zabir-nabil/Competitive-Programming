//C++ 	0.004 	1088   Accepted 
#include<stdio.h>
int main()
{
    int tc,N,temp,sum;
    scanf("%d\n",&tc);
    for(int loop = 0; loop<tc;loop++)
    {
        scanf("%d",&N);
        sum =0;
        while(N--)
        {
            scanf("%d",&temp);
            if(temp>=0)
            {
                sum +=temp ;
            }
 
        }
        printf("Case %d: %d\n",loop+1,sum);
    }
    return 0;
}