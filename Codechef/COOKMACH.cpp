#include <map>
#include <iostream>
using namespace std;
map<long long,int>map_p_o_2;
inline long long abs_2(long long a)
{
    if(a>=0)return a;
    else return -1*a;
}
int main()
{
    //2^0 = 1
map_p_o_2[2] = 1;
map_p_o_2[4] = 2;
map_p_o_2[8] = 3;
map_p_o_2[16] = 4;
map_p_o_2[32] = 5;
map_p_o_2[64] = 6;
map_p_o_2[128] = 7;
map_p_o_2[256] = 8;
map_p_o_2[512] = 9;
map_p_o_2[1024] = 10;
map_p_o_2[2048] = 11;
map_p_o_2[4096] = 12;
map_p_o_2[8192] = 13;
map_p_o_2[16384] = 14;
map_p_o_2[32768] = 15;
map_p_o_2[65536] = 16;
map_p_o_2[131072] = 17;
map_p_o_2[262144] = 18;
map_p_o_2[524288] = 19;
map_p_o_2[1048576] = 20;
map_p_o_2[2097152] = 21;
map_p_o_2[4194304] = 22;
map_p_o_2[8388608] = 23;
 
int tc;
cin>>tc;//scanf("%d",&tc);
long long a,b;
while(tc--)
{
   cin>>a>>b;// scanf("%I64d %I64d",&a,&b);
    //power of 2 case
    int destination = map_p_o_2[b];
    long long counter  = 0 ;
    while(1)
    {
 
     if(a==1)
     {
       cout<<(counter+destination)<<endl; //printf("%d\n",abs(counter+destination));
        break;
     }
    else if(map_p_o_2[a]!=0)
    {
   //     if(counter>0)
 //      cout<<(counter -1 + abs_2(destination - map_p_o_2[a]))<<endl; //printf("%d\n",abs(counter + destination - map_p_o_2[a]));
     //   else
            cout<<(counter + abs_2(destination - map_p_o_2[a]))<<endl;
        break;
    }
    else
    {
        if(a%2==0)
            a=a/2;
        else
            a=(a-1)/2;
 
            counter++;
    }
 
    }
}
    return 0;
}