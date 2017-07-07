    #include <bits/stdc++.h>
     
     
    #define loop(i,s,e) for(int i = s;i<=e;i++) //including end point
     
    #define pb(a) push_back(a)
     
    #define sqr(x) ((x)*(x))
     
    #define CIN ios_base::sync_with_stdio(0); cin.tie(0);
     
    #define ll long long
     
    #define ull unsigned long long
     
    #define SZ(a) int(a.size())
     
    #define read() freopen("input.txt", "r", stdin)
     
    #define write() freopen("output.txt", "w", stdout)
     
     
    #define ms(a,b) memset(a, b, sizeof(a))
     
    #define all(v) v.begin(), v.end()
     
    #define PI acos(-1.0)
     
    #define pf printf
     
    #define sfi(a) scanf("%d",&a);
     
    #define sfii(a,b) scanf("%d %d",&a,&b);
     
    #define sfl(a) scanf("%lld",&a);
     
    #define sfll(a,b) scanf("%lld %lld",&a,&b);
     
    #define sful(a) scanf("%llu",&a);
     
    #define sfulul(a,b) scanf("%llu %llu",&a,&b);
     
    #define sful2(a,b) scanf("%llu %llu",&a,&b); // A little different
     
    #define sfc(a) scanf("%c",&a);
     
    #define sfs(a) scanf("%s",a);
     
    #define getl(s) getline(cin,s);
     
    #define mp make_pair
     
    #define paii pair<int, int>
     
    #define padd pair<dd, dd>
     
    #define pall pair<ll, ll>
     
    #define vi vector<int>
     
    #define vll vector<ll>
     
    #define mii map<int,int>
     
    #define mlli map<ll,int>
     
    #define mib map<int,bool>
     
    #define fs first
     
    #define sc second
     
    #define CASE(t) printf("Case %d: ",++t) // t initialized 0
     
    #define cCASE(t) cout<<"Case "<<++t<<": ";
     
    #define D(v,status) cout<<status<<" "<<v<<endl;
     
    #define INF 1000000000   //10e9
     
    #define EPS 1e-9
     
    #define flc fflush(stdout); //For interactive programs , flush while using pf (that's why __c )
     
    #define CONTEST 1
    using namespace std;

    //Find c such that LCM(a,b,c) = L
    //Example, a = 10, b = 10, L = 20. Lets factorize, a = 2^1*5^1, b = 2^1*5^1, L = 2^2*5^1, here in L, I have 5^1 which could have come from either a or b.
    //but, 2^2 can't come from a or b. as I need to find the minimum so just take 2^2 as c. [Similar process as finding LCM from prime factorization, just take maximum     //prime power] Here, for each a and b compare max power of prime factor with L's prime power if both are equal we are fine, if L's power greater than a&b's max     //power then. we must have c such that c has that L's max power. so, we multiply c = 1 by prime^L's max power and so on. If, L's power less than a&b's max power
    //-> impossible.


    bool isp[1000005];
    vi prms;
    void sv()
    {
        ms(isp,true);
     
        for(ll i=2; i<=1000000; i++)
        {
            if(isp[i])
            {
                prms.pb(i);
                for(ll j=(i*i); j<=1000000; j+=i)
                {
     
                    isp[j] = false;
     
                }
            }
     
     
        }
     
     
     
    }
    map<ll,int>prmfct;
     
    ll por(ll bs, ll powr)
    {
        ll res = 1;
        for(ll ip=1; ip<=powr; ip++)
        {
            res*=bs;
        }
        return res;
    }
     
     
     
    int main()
    {
     
        sv();
        int tc,cas=0;
        sfi(tc);
        while(tc--)
        {
     
            ll a,b,L;
            sfll(a,b);
            sfl(L);
     
            ll Lc = L;
     
            for(int i=0; prms[i]<=(int)(sqrt(Lc+0.1)); i++)
            {
                while(Lc%prms[i]==0)
                {
                    prmfct[ prms[i] ]++;
                    Lc/=prms[i];
                }
                if(Lc==1)
                    break;
     
            }
     
            if(Lc!=1)
                prmfct[Lc]=1;
     
    //        for(auto it=prmfct.begin(); it!=prmfct.end(); it++)
    //        {
    //            ans = ans*()
    //            ll bs = it->first;
    //            ll pr = it->second;
    //
    //            cout<<bs<<" "<<pr<<endl;;
    //        }
     
     
     
            ll ans = 1;
     
            int flag = 1;
     
            for(int i=0; prms[i]<=max(a,b); i++)
            {
                int mxp = 0;
                int ap = 0;
                while(a%prms[i]==0)
                {
                    a/=prms[i];
                    ap++;
                }
                int bp = 0;
                while(b%prms[i]==0)
                {
                    b/=prms[i];
                    bp++;
                }
                mxp=max(ap,bp);
     
                if(mxp!=0)
                {
                    if(mxp==prmfct[ prms[i] ])
                    {
                        prmfct[prms[i]]-=mxp;
                    }
                    else if(mxp>prmfct[prms[i]])
                    {
                        flag = 0;
                        break;
                    }
                }
     
            }
     
     
     
     
            CASE(cas);
            if(flag==0)
            {
                pf("impossible\n");
                prmfct.clear();
                continue;
            }
            for(map<ll,int>::iterator it=prmfct.begin(); it!=prmfct.end(); it++)
            {
                //ans = ans*()
                ll bs = it->first;
                ll pr = it->second;
     
                ans*=por(bs,pr);
            }
     
            pf("%lld\n",ans);
     
            prmfct.clear();
     
     
     
     
     
     
     
        }
     
     
     
        return 0;
    }
     
