#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll a,b;
    scanf("%lld %lld",&a,&b);
    if(b>45)
    {
        b=b-45;
        printf("%lld %lld\n",a,b);
    }
    else
    {
        b = 60 + b -45;
        a--;
        if(a==-1)
        {
            a=23;
        }
        printf("%lld %lld\n",a,b);
    }
}
