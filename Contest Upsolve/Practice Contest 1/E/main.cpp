#include<bits/stdc++.h>
#include <complex>

#define Write freopen("out.txt","w",stdout)
#define Read freopen("in.txt","r",stdin)

#define si(a)           scanf("%d",&a)
#define sii(a,b)        scanf("%d %d",&a,&b)
#define siii(a,b,c)     scanf("%d %d %d",&a,&b,&c)

#define sl(a)           scanf("%lld",&a)
#define sll(a,b)        scanf("%lld %lld",&a,&b)
#define slll(a,b,c)     scanf("%lld %lld %lld",&a,&b,&c)

//#define m_p make_pair
#define ll long long
#define pii pair < ll , ll >

#define lim 10000000
#define mod 100007
#define dist(ax,ay,bx,by)   ((ax-bx)*(ax-bx)+(ay-by)*(ay-by))
/*Geometry*/
#define X real()
#define Y imag()
/*Geometry*/

using namespace std;

typedef complex < ll > cmp;
vector < ll > v;
vector < ll > sqr;
int main()
{

  //ll a,b;
  ///cin>>a>>b;
  ll l=10;
  ll m=1000000;
  ll cnt=0;
  /*for(ll i=1;i<=l;i++)
  {
      for(ll j=1;j<=m;j++)
      {
          ll x=(i*i)+j;
          ll p=sqrt(x);
          if(p*p==x) {
            cnt++;
            cout<<i<<" "<<j<<" "<<x<<endl;
          }
      }
  }*/

 // cout<<cnt<<endl;

 ll a,b,i,j,k;

 sll(a,b);

 for(i=1; ; i++)
 {
     ll num;

     num=i*i;

     sqr.push_back(num);

     if(num>1e13)
     {
         break;
     }
 }

 ll ans=0;

 for(i=1; i<=a; i++)
 {
     ll rng=i*i+b;

     ll up=upper_bound(sqr.begin(),sqr.end(),rng)-sqr.begin();

     up-=i;

     ans+=up;

    // cout<<"ksk: "<<i<<' '<<up<<endl;

 }

 printf("%lld\n",ans);




}


