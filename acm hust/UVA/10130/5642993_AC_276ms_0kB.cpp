#include <bits/stdc++.h>

using namespace std;

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
int main()
{
   int T;
   scanf("%d",&T);
   while(T--)
    {

        scanf("%d",&N_obj);
        for(int a=1;a<=N_obj;a++)
        {
            scanf("%d %d",&price[a],&weight[a]);
        }
        int N_ppl;
        scanf("%d",&N_ppl);
        for(int b=0;b<N_ppl;b++)
        {
            scanf("%d",&person[b]);
        }
        int ans=0,inter;
        for(int c=0;c<N_ppl;c++)
        {


            memset(dp,-1,sizeof(dp));
            CAP = person[c];
            inter=rec(0,0);
            ans+=inter;
        }
        printf("%d\n",ans);
    }
    return 0;
}
