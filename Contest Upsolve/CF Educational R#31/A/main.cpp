#include <iostream>
#define ll long long
using namespace std;

int main()
{
    ll n,t;
    cin>>n>>t;

    ll sum = 0;
    ll ans = n;
    for(ll i=1; i<=n; i++)
    {
        ll a;
        cin>>a;

        sum+=(86400-a);

        if(sum>=t)
        {
            ans = i;
            break;
        }



    }

    cout<<ans<<endl;





    return 0;
}
