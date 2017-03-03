#include <bits/stdc++.h>
    using namespace std;
    map<string,int> mp;
    int main()
    {
string month[]={"January",
     "February", "March", "April",
      "May", "June", "July", "August",
       "September", "October", "November",
       "December"};

        for(int i=0;i<12;i++)
        mp[month[i]]=i+1;

        int tc,t=1;
        scanf("%d",&tc);
        int y,m,t1,t2;char a[25];
        while(tc--)
        {
            scanf("%s %d , %d",a,&m,&y);
            t1=t2=0;
            if((y%400==0)||(y%100!=0&&y%4==0))
            {
                if(mp[a]>2)
                y++;
            }y--;
            t1+=(y/4-y/100+y/400);
            scanf("%s %d , %d",a,&m,&y);
            if((y%400==0)||(y%100!=0&&y%4==0))
            {
                if(mp[a]>2||(mp[a]==2&&m==29))
                y++;
            }y--;
            t2+=(y/4-y/100+y/400);
            printf("Case %d: %d\n",t++,t2-t1);
        }
        return 0;
    }
