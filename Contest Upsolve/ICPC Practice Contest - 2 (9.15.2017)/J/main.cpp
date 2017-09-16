#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<int>prms;
bool isp[4000006];
void sv()
{
    memset(isp,true,sizeof(isp));
    for(int i=2; i<=100000; i++)
    {
        if(isp[i])
        {
            prms.push_back(i);
            for(int j=(i*i); j<=100000; j+=i)
            {
                isp[(int)j] = false;
                //cout<<j<<endl;
            }
        }
    }

     cout<<prms.size();

}
int main()
{
    sv();
    ll n;
    while(~scanf("%lld",&n))
    {
        int fpf = 0;
        int prmfact = 0;
        for(int i=0; i<prms.size(); i++)
        {
            while(n%prms[i]==0)
            {
                prmfact++;
                fpf = prms[i];
            }
        }

        if(n!=1)
            prmfact++;

        if(prmfact==2)
        {
            printf("2\n");
        }
        else if(prmfact==1)
        {
            printf("1\n0\n");
        }
        else
        {
            printf("1\n%d\n",fpf);
        }


    }

    return 0;
}
