
#include <bits/stdc++.h>
#define NMX 6015
using namespace std;
long long dp [6020];
int cubes[15];
/*
int dp[1002][32];
int price[1002];
int weight[1002];
int person[105];
int CAP;
int N_obj;
int rec(int i,int w)
{
	if(i==N_obj+1) return 0; //Every object has been assumed
	if(dp[i][w]!=-1) return dp[i][w]; //previosuly calculated state
	int profit1=0,profit2=0;
	if(w+weight[i]<=CAP)
		profit1=price[i]+rec(i+1,w+weight[i]);//If I take ith object

	profit2=rec(i+1,w); //If I dont take ith object
	dp[i][w]=max(profit1,profit2); //Will take the maximum
	return dp[i][w];
}
*/
void prec()
{
        memset (dp, 0, sizeof (dp));

    dp [0] = 1;

    for ( int i = 0; i < 11; i++ ) {
        for ( int j = 1; j <= NMX; j++ ) {
            if (( j - cubes [i])>=0)
                dp [j] += dp [j - cubes [i]];
        }
    }

}
int main ()
{

    cubes[0] = 1;
    cubes[1] = 2;
    cubes[2] = 4;cubes[3] = 10;cubes[4] = 20;cubes[5] = 40;
    cubes[6] = 100;cubes[7] = 200;cubes[8] = 400;cubes[9] = 1000;
    cubes[10] = 2000;


    double in2;
    prec();

    while ( scanf ("%lf", &in2) ) {
        if ( in2 == 0 ) break;
        int index = in2 * 20;

        printf ("%6.2lf%17lld\n", in2, dp [index]);
    }

    return 0;
}

