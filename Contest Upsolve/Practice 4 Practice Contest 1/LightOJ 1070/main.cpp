#include <bits/stdc++.h>
using namespace std;

//MATRIX EXPO MINIMAL LIBRARY

#define dim 2
#define mod 10000
#define mod_required 0
#define dtype unsigned long long
#define ptype unsigned long long

///2^64 mod unsigned long long
///2^32 mod unsigned int
///Calculate (m^g(N))*F(base) = F(N)

struct mat
{
    long long m[dim][dim];
    int row, col;
};


// Calculates r = a*b
mat mul(mat a, mat b)
{

    if(a.col!=b.row)
    {
        printf("Error\n");
        return a;
    }
    mat r;
    r.row = a.row;
    r.col = b.col;
    for (int i = 0; i < r.row; i++)
    {
        for (int j = 0; j < r.col; j++)
        {
            dtype sum = 0;
            for (int k = 0; k < a.col;  k++)
            {
                sum += a.m[i][k] * b.m[k][j];
                if(mod_required)
                {
                    sum %= mod;
                }
            }
            r.m[i][j] = sum;
        }
    }
    return r;
}

// m^p calculation
mat power(mat m, ptype p)
{

    if (p == 1) return m;
    if (p % 2 == 1)
        return mul(m, power(m, p - 1));
    mat ret = power(m, p / 2);
    ret = mul(ret, ret);
    return ret;
}
void dbg_mat(mat a)
{
    cout<<a.row<<" by "<<a.col<<endl;
    for(int i=0;i<a.row;i++)
    {
        for(int j=0;j<a.col;j++)
        {
            cout<<a.m[i][j]<<" ";
        }
        cout<<endl;
    }

}
//matrix initialization
/*
int m_ar[dim][dim] =
{
    {0,0},
    {0,0},

};
mat mp;
mat bp;
void m_cop(mat a,int ar[][dim])
{
    for(int i=0;i<a.row;i++)
    {
        for(int j=0;j<a.col;j++)
        {
            a.m[i][j] = ar[i][j];
        }
    }

}
void mat_cop()
{
    m_cop(mp,m_ar);
    bp.m[0][0] = 1;
    bp.m[0][0] = 1;
    bp.m[0][0] = 1;
    bp.m[0][0] = 1;
    bp.m[0][0] = 1;
}
*/
int main()
{
    int tc,cas = 0;
    scanf("%d",&tc);
    while(tc--)
    {
        dtype p,q,n;
        scanf("%llu %llu %llu",&p,&q,&n);
        if(n==0)
        {
            printf("Case %d: 2\n",++cas);
            continue;

        }
        else if(n==1)
        {
            printf("Case %d: %llu\n",++cas,p);
            continue;
        }
        mat mp;
        mp.row = 2;
        mp.col = 2;
        mp.m[0][0] = p;
        mp.m[0][1] = -q;
        mp.m[1][0] = 1;
        mp.m[1][1] = 0;

        //dbg_mat(mp);

        mat bp;
        bp.row = 2;
        bp.col = 1;
        bp.m[0][0] = p;
        bp.m[1][0] = 2;

        //dbg_mat(bp);

        mat pmat = power(mp,n-1);

        //dbg_mat(pmat);
        mat ans = mul(pmat,bp);
        //dbg_mat(ans);

        dtype fans = ans.m[0][0];

        printf("Case %d: %llu\n",++cas,fans);





    }




    return 0;
}
