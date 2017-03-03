#include <bits/stdc++.h>
#define p_v(v) for(int a=0;a<v.size();a++)cout<<v[a]<<" ";cout<<endl;
using namespace std;
typedef unsigned long long ULL;

//cout<<powl(2,60)<<endl;
double trn(double x,double par,double y,double par2,double his)
{
    return x*par + y*par2 + his;
}
double d(double x,double y)
{
    return sqrt(x*x+y*y);
}
int main ()
{
	int T;
	scanf("%d",&T);
	for (int t=1;t<=T;t++)
	{




    double Ax,Bx,Ay,By,B,C,D,Cx,Cy,Dx,Dy,x,y,z,AC;



double hei;
	bool flag=false;
	scanf("%lf %lf %lf %lf %lf %lf %lf",&Ax,&Ay,&Bx,&By,&B,&C,&D);
	x=Bx-Ax;
	y=By-Ay;
	AC= d(x,y);
	double st,ct;
	st=y/AC;
	ct=x/AC;
	x=D;
	z=B;
	y=AC-C;
	double m=(x+y+z)/2;
	double s=sqrt(m*(m-x)*(m-y)*(m-z));
	if (z*z > x*x+y*y)
		flag=true;
	hei = 2.000000f*s/y;
	double tmp;
	tmp=fabs( x*x - hei*hei );

	tmp=sqrt(tmp);
	if (flag)
    {


		tmp*=-1;
    }
	x=tmp;
	y=hei;
	Cx = trn(x,ct,y,-st,Ax);
	Cy = trn(x,st,y,ct,Ay);


	x=tmp+C;y=hei;

	Dx = trn(x,ct,y,-st,Ax);
	Dy = trn(x,st,y,ct,Ay);

printf("Case %d:\n",t);
	printf("%.8lf %.8lf %.8lf %.8lf\n",Dx,Dy,Cx,Cy);

	}
	return 0;
}
