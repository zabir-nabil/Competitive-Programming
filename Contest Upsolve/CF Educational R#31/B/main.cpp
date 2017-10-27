#include <iostream>
#define ll long long
using namespace std;
ll arr[100005];
int main()
{
    ll n;
    ll x;
    while(cin>>n>>x)
    {
        ll sum = 0;
        for(ll i=1; i<=n; i++)
        {
            cin>>arr[i];
            sum+=arr[i];
        }

        if(sum+(n-1)==x)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }


    }
    return 0;
}
