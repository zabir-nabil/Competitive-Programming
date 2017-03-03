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
struct point3d{
int left_x,rgt_x;
int down_y,up_y;
int down_z,up_z;
};
point3d p3d[109];
point3d inter_p(point3d p1,point3d p2)
{
    point3d intersected_p;
 
 
    int leftx1 = p1.left_x;
    int leftx2 = p2.left_x;
    int rightx1 = p1.rgt_x;
    int rightx2 = p2.rgt_x;
    int right_most_leftX =
    max(leftx1,leftx2);
    int left_most_rightX =
    min(rightx1,rightx2);
 
    int downy1 = p1.down_y;
    int downy2 = p2.down_y;
    int upy1 = p1.up_y;
    int upy2 = p2.up_y;
    int up_most_downY =
    max(downy1,downy2);
    int down_most_upY =
    min(upy1,upy2);
 
    int downz1 = p1.down_z;
    int downz2 = p2.down_z;
    int upz1 = p1.up_z;
    int upz2 = p2.up_z;
    int up_most_downZ =
    max(downz1,downz2);
    int down_most_upZ =
    min(upz1,upz2);
 
    if(right_most_leftX<=left_most_rightX
       && up_most_downY<=down_most_upY
       && up_most_downZ<=up_most_downZ)
    {
        intersected_p.left_x =
        right_most_leftX;
        intersected_p.rgt_x =
        left_most_rightX;
 
        intersected_p.down_y =
        up_most_downY;
        intersected_p.up_y =
        down_most_upY;
 
        intersected_p.down_z =
        up_most_downZ;
        intersected_p.up_z =
        down_most_upZ;
 
 
    }
    else
    {
        intersected_p.left_x = INF;
    }
 
    return intersected_p;
 
 
}
int volume(point3d p)
{
    int vol = (p.rgt_x - p.left_x)*
    (p.up_y - p.down_y)*(p.up_z - p.down_z);
 
    return vol;
}
int main()
{
 
    int tc,cas  = 0;
    //write();
    sfi(tc);
    while(tc--)
    {
        int N;
        sfi(N);
        loop(i,1,N)
        {
            int x1,x2,y1,y2,z1,z2;
            sfii(x1,y1);
            sfii(z1,x2);
            sfii(y2,z2);
            point3d temp;
            temp.left_x = x1;
            temp.rgt_x = x2;
            temp.down_y = y1;
            temp.up_y = y2;
            temp.down_z = z1;
            temp.up_z = z2;
            p3d[i] = temp;
        }
        int ans = 1;
        point3d cur_intersection = p3d[1];
        loop(i,2,N)
        {
            point3d newp = p3d[i];
 
            point3d intersex =
            inter_p(cur_intersection,p3d[i]);
            if(intersex.left_x==INF)
            {
                ans = 0;
                break;
            }
            else
            {
                cur_intersection = intersex;
            }
        }
        CASE(cas);
        if(N==1)
        {
            pf("%d\n",volume(p3d[1]));
        }
        else if(ans==0)
        {
            pf("%d\n",0);
        }
        else
        {
            pf("%d\n",volume(cur_intersection));
        }
 
 
 
    }
 
 
 
    return 0;
}