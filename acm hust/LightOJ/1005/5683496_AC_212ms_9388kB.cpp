#include <bits/stdc++.h>
 
using namespace std;
typedef unsigned long long ull;
 
ull dp_table[33][33][905];
 inline ull C(int m,int n,int k)
{
    if(dp_table[m][n][k]!=-1) return dp_table[m][n][k] ;
    else
    {
        //base cases
        if(k>m || k>n)
        {
            dp_table[m][n][k] = 0;
            return dp_table[m][n][k] ;
        }
        else if(k==0)
        {
            dp_table[m][n][k] = 1;
            return dp_table[m][n][k] ;
 
        }
        else if(m==1)
        {
            dp_table[m][n][k] = n;
            return dp_table[m][n][k] ;
 
        }
else if(n==1)
        {
            dp_table[m][n][k] = m;
            return dp_table[m][n][k] ;
 
        }
        else
        {
            dp_table[m][n][k] = C(m-1,n,k) + n*(C(m-1,n-1,k-1));
            return dp_table[m][n][k] ;
        }
    }
}
inline void init()
{
    for(int a = 0;a<33;a++)
        for(int b = 0;b<33;b++)
            for(int c = 0;c<905;c++)
                dp_table[a][b][c] = -1;
}
int main()
{
    int tc;
    scanf("%d",&tc);
    for(int testcase = 1;testcase<=tc;testcase++)
    {
        init();
        int n,k;
        scanf("%d %d",&n,&k);
        printf("Case %d: %llu\n",testcase,C(n,n,k));
 
 
    }
 
    return 0;
}