#include <bits/stdc++.h>
 
using namespace std;
int dp[55][10][10];
string sss;
int n;
int isvow(char cc)
{
    if( cc == 'A' ||  cc == 'E' ||  cc == 'I' ||  cc == 'O' ||  cc == 'U' )
        return 1;
 
    return 0;
}
int rec(int idx,int v,int c)
{
    char cc = sss[idx] ; int temp1,temp2;
 
    if(v==3 || c==5) return 7; // bad
    if( idx == n) return 5;
    if(dp[idx][v][c] != -1) return dp[idx][v][c] ;
 
    if( isvow(cc) )
        return dp[idx][v][c] = rec(idx+1 , v + 1 , 0);
    else if( cc == '?'){
      //  return dp[idx][v][c] = rec(idx + 1 , v+1 , 0) + rec(idx+1,0,c+1) ;
        temp1 = rec(idx + 1 , v+1 , 0) ;
        temp2 = rec(idx+1,0,c+1) ;
        if( temp1 == temp2)
        {
            return dp[idx][v][c]  = temp1;
        }
        else
        {
            return dp[idx][v][c]  = temp1 + temp2;
        }
    }
    else return dp[idx][v][c] = rec(idx+1,0,c+1);
 
}
int main()
{
    int tc;
    cin>>tc;int cas = 0;
    while(tc--)
    {
        cin>>sss ;
        n = sss.length();
        memset(dp,-1,sizeof(dp));
        int ans = rec(0,0,0);
        //cout<<ans<<endl;
        if(ans == 5 )
            printf("Case %d: GOOD\n",++cas);
        else if(ans == 7 )
            printf("Case %d: BAD\n",++cas);
        else
            printf("Case %d: MIXED\n",++cas);
 
            sss.clear();
 
    }
    return 0;
}