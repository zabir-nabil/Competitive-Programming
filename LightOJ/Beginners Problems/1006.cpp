//
#include <cstdio>
#include <vector>
 
#define param 10000007
using namespace std;
 
vector<int> dp;
int a, b, c, d, e, f;
int fn( int n ) {
    if( n == 0 ) return a;
    if( n == 1 ) return b;
    if( n == 2 ) return c;
    if( n == 3 ) return d;
    if( n == 4 ) return e;
    if( n == 5 ) return f;
    if(dp[n]==-1){
 
//if(dp[n-2]> param)
    long xxx = ( fn(n-1)%param + fn(n-2)%param + fn(n-3)%param + fn(n-4)%param + fn(n-5)%param + fn(n-6)%param )%param;
dp[n] = xxx;
return xxx;
 
}
else
    return dp[n];
 
}
int main() {
    int n, caseno = 0, cases;
    scanf("%d", &cases);
    while( cases-- ) {
        scanf("%d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &n);
        dp.assign((size_t)n+5,-1);
        dp[0] = a;
        dp[1] = b;
        dp[2] = c;
        dp[3] = d;
        dp[4] = e;
        dp[5] = f;
        printf("Case %d: %d\n", ++caseno, fn(n)%param);//fn(n) % 10000007);
    }
    return 0;
}