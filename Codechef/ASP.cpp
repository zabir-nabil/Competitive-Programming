    #include<bits/stdc++.h>
     
    using namespace std;
     
    #define rep(i,b) for(i=0;i<b;i++)
    #define rep1(i,b) for(i=1;i<=b;i++)
     
    #define plln(n) printf("%lld\n",n)
     
    #define s3ll(n1,n2,n3) scanf("%lld%lld%lld",&n1,&n2,&n3)
    #define s2ll(n1,n2) scanf("%lld%lld",&n1,&n2)
    #define sll(n) scanf("%lld",&n)
     
    #define countSetBits(n) __builtin_popcountll(n)
     
    typedef long long LL;
     
    #define mod 1000000007
    #define mx 999999
    int main()
    {
        LL t,n,i;
        sll(t);
        while(t--)
        {
            sll(n);
            LL a[n+5];
            LL flag=1;
            rep1(i,n)
            {
                sll(a[i]);
                
                }
                rep1(i,n)
                {
               LL cnt=(a[i]-i);
               if((cnt<=-2)){
                flag=0;break;
                }
            }
            if(flag)
                printf("YES\n");
            else
                printf("NO\n");
        }
        return 0;
    } 