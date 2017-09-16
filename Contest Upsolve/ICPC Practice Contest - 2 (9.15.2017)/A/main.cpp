#include <bits/stdc++.h>

using namespace std;
int n;
int ar[1000005];
int br[1000005];
int rec(int i,int j,int pl)
{
    //if()
    if(pl==1)
    {

    }
    return 0;
}
#define ll  long long
int main()
{
    ll m,k;
    int n;
    while(~scanf("%d",&n))
    {
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&ar[i]);
        }

        for(int i=1; i<=n; i++)
        {
            scanf("%d",&br[i]);
        }

        int sum1 = 0;
        int tos = 0;
        int sum2 = 0;
        int flg1 = 1;
        int cnt1 = 0;
        for(int i=1; i<=n; i++)
        {
            if(flg1)
            {
                sum1+=ar[i];
                tos+=ar[i]-br[i];
                cnt1++;
                if(tos<0)
                {
                    flg1 = 0;
                    tos=0;
                }

            }
            else
            {
                sum2+=ar[i];
                tos+=ar[i]-br[i];
                if(tos<0)
                {
                    break;
                }
            }

        }

        if(sum2>sum1)
        {
            printf("%d\n",cnt1);
        }
        else
        {
            printf("0\n");
        }



    }

    return 0;
}
