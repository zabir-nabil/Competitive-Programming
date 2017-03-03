#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    if(n==1)
        printf("1\n");
    else
    {
        printf("%d ",n);
        for(int a=1;a<=n-2;a++)
        {

            printf("%d ",a);
        }
        printf("%d\n",n-1);
    }

    return 0;
}
