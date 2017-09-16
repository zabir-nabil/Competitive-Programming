#include <bits/stdc++.h>

using namespace std;

int main()
{
    int A,B,C,D,E,F;
    cin>>A>>B>>C>>D>>E>>F;

    double mxd = 0.00f;

    int sug = 0;
    int ansf = 0;

    double mxc = 0.00f;

    int mxl = 100;


    for(int a=0; a<=mxl; a++)
    {
        for(int b=0; b<=mxl; b++)
        {
            for(int c=0; c<=mxl; c++)
            {
                for(int d=0; d<=mxl; d++)
                {
                    int f = a*100*A
                            + b*100*B
                            + c*C + d*D;

                    int csug = c*C + d*D;

                    int lp = E*(a*100*A
                                + b*100*B);
                    int rp = 100*(c*C + d*D);
                    mxc = (100.00)*(csug)/(1.00*f);


                    if(f<=F && lp>=rp)
                    {
                        //cout<<"aha"<<endl;
                        //cout<<a<<" "<<b<<endl;
                        double curd
                            = (100.00*csug)/((1.00)*(f));

                        if(curd>=mxd)
                        {
                            mxd = curd;
                            ansf = f;
                            sug = csug;
                        }


                    }

                }
            }
        }
    }

    //cout<<mxc<<endl;

    printf("%d %d\n",ansf,sug);
    return 0;
}
