#include <bits/stdc++.h>
int banana[205][105];
int dp_table[205][105];
int N;
using namespace std;
inline int recur(int level,int index)
{
    if(dp_table[level][index]!=-1) return dp_table[level][index];
 
    if(level ==1 && index == 1)
    {
        dp_table[level][index] = banana[level][index];
        return dp_table[level][index];
    }
    if(level == index)
    {
        dp_table[level][index] = recur(level-1,index-1) + banana[level][index];
         return dp_table[level][index];
    }
    if(level <= N)
    {
        dp_table[level][index] = max(recur(level-1,index-1)+banana[level][index],recur(level-1,index)+banana[level][index]);
        return dp_table[level][index];
    }
    if(level>N)
    {
        dp_table[level][index] = max(recur(level-1,index+1)+banana[level][index],recur(level-1,index)+banana[level][index]);
        return dp_table[level][index];
    }
 
}
int main()
{
    int tc ;
    scanf("%d",&tc);
    for(int testcase = 1;testcase <= tc;testcase++)
    {
 
 
 
    scanf("%d",&N);
 
    for(int level = 1 ;level < 2*N ;level++)
    {
        int temp;
        if(level<=N)
        {
            for(int element = 1;element<=level;element++)
                {
                    scanf("%d",&temp);
                    banana[level][element] = temp;
                    dp_table[level][element] = -1;
                }
        }
 
        if(level>N)
        {
            for(int element = 1;element<=N-(level-N);element++)
            {
                    scanf("%d",&temp);
                    banana[level][element] = temp;
                    dp_table[level][element] = -1;
            }
 
 
        }
     }
     unsigned long long ans = recur((N*2)-1,1);
     printf("Case %d: %llu\n",testcase,ans);
  //   if(testcase!=tc)printf("\n");
    }
return 0;
}