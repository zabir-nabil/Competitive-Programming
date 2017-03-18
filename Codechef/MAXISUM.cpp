#include <bits/stdc++.h>
 
using namespace std;
#define ll long long
ll A[100005];
ll B[100005];
int main()
{
   int T;
   cin>>T;
   while(T--)
   {
       int N;
       cin>>N;
       int K;
       cin>>K;
       int mxI = 0;ll mx = -999999;
       int PorN = -11;
       for(int a=0;a<N;a++)
       {
           cin>>A[a];
 
 
       }
      for(int a=0;a<N;a++)
       {
           cin>>B[a];
            if(B[a]>mx)
           {
               mx = B[a];
               mxI = a;
               PorN = 1; //pos
           }
           if(-B[a]>mx)
           {
               mx = -B[a];
               mxI = a;
               PorN = 2; //neg
           }
 
 
       }
       ll ans = 0;
 
       for(int a=0;a<N;a++)
       {
           if(a!=mxI)ans+= A[a]*B[a];
       }
 
      if(PorN == 1)
      {
          ans += B[mxI]*( A[mxI] + K  );
      }
      else
      {
          ans+= B[mxI]*(A[mxI] - K);
      }
       cout<<ans<<endl;
 
   }
    return 0;
}
 