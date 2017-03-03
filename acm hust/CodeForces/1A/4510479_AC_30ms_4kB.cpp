#include <bits/stdc++.h>

using namespace std;
long long n,m,a;
int main()
{

    scanf("%I64d %I64d %I64d",&n,&m,&a);
    long long temp_wid_a = n/a;
    long long temp_hei_a = m/a;
    long long ans1 = 0,ans2=0,ans =0;
    if(temp_wid_a*a == n)
        ans1+=temp_wid_a;
    else  ans1+=temp_wid_a + 1;
    if(temp_hei_a*a == m)
        ans2+=temp_hei_a;
    else  ans2+=temp_hei_a + 1;
ans = (ans1*ans2);

    printf("%I64d\n",ans);
    return 0;
}
