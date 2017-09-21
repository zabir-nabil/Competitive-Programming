#include <iostream>

using namespace std;
string ss;
bool ispal(int i,int j)
{
    if(j<=i)
        return 1;

    for(int x=i;x<=j/2;x++)
    {
        if(ss[x]!=ss[j-x])
        {
            return 0;
        }

    }

    return 1;

}
int main()
{

    while(cin>>ss)
    {
        for(int i=0; i<ss.length(); i++)
        {
            int flg = 1;
            for(int x=i; x<ss.length(); x++)
            {
                if(ss[x]!='0')
                {
                    flg = 0;
                }
            }


            if(flg && ispal(0,i-1))
            {
                cout<<"YES"<<endl;
                return 0;
            }
        }

        if(ispal(0,ss.length()-1))
        {
            cout<<"YES"<<endl;
            return 0;
        }

        cout<<"NO"<<endl;



    }
    return 0;
}