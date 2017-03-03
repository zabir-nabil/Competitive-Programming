

/****************************************
              Zerus97
*****************************************/

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

//CONTEST MATRIX LIB v1.1

#define GB 0

#define dim 4

#define mat vector<vector<ll> >

#define matmod 1000000007

mat GBv;
ll a,b,c;
ll idmat[] = //Each row
{
    1,4,7,0 ,
    2,5,8,0 ,
    3,6,9,0 ,
    6,15,24,0
};
ll base[] =
{
    1,
    1,
    1,
    3
};
mat assImat(ll arr[],int row,int col) // assign identity matrix
{
    mat X;



    int arridx = 0;

    vll rows;



    if(!rows.empty())
    {
        rows.clear();
    }

    loop(r,0,row-1)
    {

        loop(c,0,col-1)
        {
            rows.pb(arr[arridx]);

            arridx++;
        }
        X.pb(rows);
        rows.clear();


    }

    return X;

}

mat applymod(mat A,int row,int col)
{

    loop(r,0,row-1)
    {
        loop(c,0,col-1)
        A[r][c]%=matmod;
    }
    return A;
}

mat matmul(mat A,mat B,int ra,int ca,int rb,int cb)
{
    if(ca!=rb)
    {
        cout<<"ERR dim"<<endl;
        return GBv;
    }

    mat res;

    vll rows;

    loop(amr,0,ra-1) //ans matrix row
    {
        loop(amc,0,rb-1)
        {
            ll rowi = 0;
            loop(crc,0,ca-1) //common row column
            {
                rowi= ((rowi%matmod) +
                (A[amr][crc]%matmod)*
                       (B[crc][amc]%matmod))%matmod;
            }

            rows.pb(rowi);

        }

        res.pb(rows);
        rows.clear();


    }

    return res;


}
mat expo(mat A, int row,int col,ll p)
{
    if(p==1){
        mat Ap = applymod(A,row,col);
        return Ap;
    }

    else if(p%2==0)
    {
        mat halfp = expo(A,row,col,p/2);
        mat halfp2 = applymod(halfp,
                              row,col);
        mat res = matmul(halfp2,halfp2,
                         row,col,row,col);
        return res;
    }
    else if(p%2==1)
    {
        mat halfp = expo(A,row,col,p/2);
        mat halfp2 = applymod(halfp,
                              row,col);
        mat resp = matmul(halfp2,halfp2,
                          row,col,row,col);
        mat resp2 = applymod(resp,row,col);
        mat finres = matmul(resp2,A,
                            row,col,row,col);
        return finres;
    }



}
void showmat(mat A,int row,int col)
{
    loop(r,0,row-1)
    {
        loop(c,0,col-1)
        cout<<A[r][c]<<" ";
        cout<<endl;
    }
}
ll fun(int n)
{
    if(n==1)
        return 3;

    mat Id = assImat(idmat,4,4);

    //Id[0][0] = a;
    //Id[0][2] = b;
    //Id[0][3] = 1;


    //showmat(Id,dim,dim);

    mat basemat = assImat(base,4,1);

    //basemat[3][0] = c;

    //showmat(basemat,4,1);

    mat expmat = expo(Id,dim,dim,n-1);
    //showmat(expmat,4,4);
    //showmat(expmat,dim,dim);

    mat expmat2 = applymod(expmat,
                           dim,dim);


    //showmat(expmat2,4,4);
    mat ans = matmul(expmat2,basemat,dim,
                     dim,dim,1);

    //showmat(ans,dim,1);
    ll ansfn_p1 = ans[3][0];
    //cout<<ans[0][3]<<endl;
    //cout<<ansfn_p1<<endl;

    return (ansfn_p1%matmod);

}
int main()
{

    


    int tc,cas  = 0;

    sfi(tc);
    while(tc--)
    {
       ll n;
       sfl(n);
       //sfll(n,a);
       //sfll(b,c);

       ll ans = fun(n);


       //CASE(cas);
       pf("%lld\n",ans);

    }





    return 0;
}
