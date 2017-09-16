#include <bits/stdc++.h>

using namespace std;

#define ll long long int

int status[3700005];

vector<int>prms;

int main()
{
    ll n,i,si,j;





    si=int(sqrt((double)n+1));

    for(i=2; i<=3600000; i++)
    {
        if(status[i]==0)
        {
            prms.push_back(i);
            for(j=i; j<=3600000; j+=i)
            {
                status[j]++;
            }
        }
    }

    //for(int i=1;i<=30;i++)
    //    cout<<status[i]<<endl;


    while(cin>>n)
    {
        ll nc = n;

        int prmfact = 0;
        int fpf = 1;
        int cnt = 0;
        for(int i=0; i<prms.size(); i++)
        {

            while(n%prms[i]==0)
            {
                prmfact++;

                n/=prms[i];

                if(cnt<2)
                {
                    cnt++;
                fpf *= prms[i];
                }
            }
        }

        if(n!=1)
            prmfact++;

        if(nc==1)
        {
            printf("1\n0\n");
        }

        else if(prmfact==1)
        {
            printf("1\n0\n");
        }
        else if(prmfact==2)
        {
            printf("2\n");
        }
        else
        {
            printf("1\n%d\n",fpf);
        }
    }

    return 0;
}
