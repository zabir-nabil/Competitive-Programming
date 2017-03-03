#include <bits/stdc++.h>
#define INF 99999999
using namespace std;
int N,K;
int arr[1005];
int solution[1005];
 int mx_pos_walk  ; //cum_sum
 //1 2 3 4 5
 //7 6 4 3 2
bool is_a_solution(int max_walk)
{
    int idx = 1; int cum_sum = 0; int night;
    for(night = 1; night <= K+1 ; night++)
    {
        cum_sum = 0;


        while( ( (arr[idx] + cum_sum) <= max_walk) && ((K+ 1- night )<=(N+1-idx)) && (idx<=N+1))//&& (N+1 - idx)>night
        {

            cum_sum += arr[idx] ;

            idx++;
        }
        if(cum_sum == 0)return false;//could n't pack box with any balls
        solution[night] = cum_sum ;
    }
while(idx<=N+1)
{
    solution[K+1]+=arr[idx];
    idx++;
}
if(solution[K+1]<=max_walk)return true;

    return false;

}
int solve_binary_search(int lo,int hi)
{

    //No No No No -- [Yes] -- Yes Yes  <- I am looking for that Yes
    if( is_a_solution(lo) )
        return lo;

    int mid;

    while(lo<=hi)
    {
        mid = ( lo + hi )/2;

        if( is_a_solution(mid) && !is_a_solution(mid-1) )
        {
            is_a_solution(mid); //again need to call this as is_a_solution(mid-1) is overwriting solution array
            //alternative call is_a_solution(mid-1) first
            return mid;
        }
        if(is_a_solution(mid)) // I am in the Yes region Need to adjust the upper mark
        {
            hi = mid - 1;
        }
        if(!is_a_solution(mid)) // In the No region . Need to shift the left mark a little right
        {
            lo = mid + 1 ;
        }
    }




}
int main()
{
    int tc;int cas = 0;

    cin>>tc;
    while(tc--)
    {
    cin>>N>>K;
    int mn_pos_walk = INF;
    mx_pos_walk = 0;
    for(int x = 1;x<=N+1;x++){
        cin>>arr[x];
        mx_pos_walk += arr[x] ; //Don't need to check for larger than the sum of all walks as predicate will reply YES
        mn_pos_walk = min(mn_pos_walk , arr[x]) ; //We know for sure we cant get maximum walk less than the minimum walk
    }
    int ans = solve_binary_search(mn_pos_walk,mx_pos_walk);

    printf("Case %d: %d\n",++cas,ans);
    for(int nn = 1;nn<=K+1;nn++)
        printf("%d\n",solution[nn]);


    }
    return 0;
}
