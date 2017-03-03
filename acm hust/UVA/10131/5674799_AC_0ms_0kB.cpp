#include <bits/stdc++.h>

using namespace std;
struct elephant{
int weight;
int IQ;
int ID;
}Eloa[1005];

bool compare(elephant e1,elephant e2)
{
    return e1.weight < e2.weight ;
}

int lis[1005];
vector<int>sol_set;
int LIS_N_2(int n)
{
   for(int a=0;a<n;a++)
   {
       lis[a] = 1;
   }

   int mx = 0;
   for(int a = 0;a<n;a++)
   {
       for(int b=0;b<a;b++)
       {
           int iqA = Eloa[a].IQ ; int iqB = Eloa[b].IQ ;
           int wtA = Eloa[a].weight ; int wtB = Eloa[b].weight ;
           if(  iqB > iqA && wtA > wtB )
           lis[a] = max( lis[b] + 1 , lis[a] );

       }
       mx = max(mx,lis[a]);


   }

   return mx;


}
int main()
{
    int idx = 0;

    int tmp,tmp2;
    while(scanf("%d %d",&tmp,&tmp2)==2)
    {
        Eloa[idx].ID = idx;

        Eloa[idx].weight = tmp;

        Eloa[idx].IQ = tmp2;


        idx++;

    }

    sort(Eloa,Eloa+idx,compare);

/*
for(int a=0;a<idx;a++)
{
    cout<<Eloa[a].weight<<"  "<<Eloa[a].IQ<<endl;
}
*/

int mx = LIS_N_2(idx);
int mx_ = mx;

//Final solution printer

for(int x = idx -1 ; x>=0;x--)
{

    if(lis[x] == mx)
    {
        sol_set.push_back(x);
        mx--;
    }

}
reverse(sol_set.begin(),sol_set.end());
cout<<mx_<<endl;
for(int a=0;a<sol_set.size();a++)
    cout<<Eloa[ sol_set[a] ].ID + 1 <<endl;

    return 0;
}
