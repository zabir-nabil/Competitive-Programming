#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    scanf("%d",&T);
    long long ss = 0;
    while(T--)
    {
        string s;int d;
        cin>>s;
        if(s[0]=='d')
        {
            cin>>d;
            ss+=d;
        }
        else
        {
            cout<<ss<<"\n";
        }
    }


    return 0;
}
