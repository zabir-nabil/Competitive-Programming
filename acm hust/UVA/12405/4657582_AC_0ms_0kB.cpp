#include <bits/stdc++.h>
#define p_v(v) for(int a=0;a<v.size();a++)cout<<v[a]<<" ";cout<<endl;
using namespace std;
int N;
vector<int>fld;
int main()
{

    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++)
{



    scanf("%d",&N);
    for(int a=0; a<N; a++)
    {
        char c;
        cin>>c;
        if(c=='.')
            fld.push_back(1);
        else
            fld.push_back(0);

    }
   // p_v(fld);
    int cnt = 0;
    int ans = 0;
    for(int a=0; a<N;)
    {
       if(fld[a]==1)
        {cnt++;
       a+=3;}
       else
        a++;
    }

    printf("Case %d: %d\n",t,cnt);
    fld.clear();


}
    return 0;
}
