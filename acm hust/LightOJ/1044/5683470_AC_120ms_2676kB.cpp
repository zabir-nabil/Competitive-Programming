#include <bits/stdc++.h>
 
using namespace std;
string s;
int n;
bool is_p[1002][1002];
int dp[1002];
vector<int>tmp;
inline int rec(int i)
{
 
    if(i==n)
        return 0;
    else
    {
        for(int j=i; j<n; j++)
        {
            if(is_p[i][j]==true)
            {
                if(dp[j+1]==-1)
 
                {
                    dp[j+1] = rec(j+1);
                    tmp.push_back(dp[j+1]+1);
                    }
                    else
                    {
                        tmp.push_back(dp[j+1] + 1);
                    }
 
 
            }
        }
        if(tmp.empty())
            return 0;
        else
        {
            int me = *(min_element(tmp.begin(),tmp.end()));
            tmp.clear();
            return me;
        }
    }
}
int main()
{
    int tc,cas = 1;
    scanf("%d",&tc);
    while(tc--){
 
 
    cin>>s;
    n = s.length();
    for(int a=0; a<n; a++)
    {
        is_p[a][a] = true;
    }
 
    for(int a=0; a<n-1; a++)
    {
        if(s[a]==s[a+1])
            is_p[a][a+1] = true;
    }
    for(int len = 3; len<=n; len++)
    {
 
        for(int a=0; a<=n-len; a++)
        {
            if(s[a]==s[a+len-1] && is_p[a+1][a+len-2]==true)
                is_p[a][a+len-1] = true;
        }
    }
 
   /* while(1)
    {
        int a,b;
        cin>>a>>b;
        if(a<=b && a>=1 && b <=s.length())
            cout<<is_p[a-1][b-1]<<endl;
        else
 
            cout<<"Out of range!"<<endl;
    }
 
*/
for(int x=0;x<1001;x++)
    dp[x] = -1;
 
    tmp.clear();
 
printf("Case %d: %d\n",cas++,rec(0));
 
s.clear();
 
for(int x=0;x<1002;x++)
    for(int y=0;y<1002;y++)
    is_p[x][y] =0;
    }
    return 0;
}