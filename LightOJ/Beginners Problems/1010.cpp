//C++ 	0.024 	1088   Accepted    
 #include<stdio.h>
    int main()
    {
     
        int tc,cas = 0 ;
        int ans = 0;
        scanf("%d",&tc);
        while(tc--)
        {
            int m,n;
            scanf("%d %d",&m,&n);
            //ans = solve(m,n);
            if(m==1)
                ans = n;
            else if(n==1)
                ans = m;
            else if(m==2)
            {
                ans = 0;
                for(int i=1,cn=1; i<=n; i+=4,cn++)
                {
     
                //    if(cn&1)
                    {
                        if(i==n)
                            ans +=2;
                        else
                            ans += 4;
                    }
                }
            }
            else if(n==2)
            {
                ans = 0;
                for(int i=1,cn=1; i<=m; i+=4,cn++)
                {
     
               //     if(cn&1)
                    {
                        if(i==m)
                            ans +=2;
                        else
                            ans += 4;
                    }
                }
            }
     
     
            else if(m&1)//odd
            {
                if(n&1)//odd
                    ans= (m/2 + 1)*(n/2 + 1) + (m/2)*(n/2);
                else //m odd n even
                    ans= (m/2 + 1)*(n/2) + (m/2)*(n/2);
            }
            else
            {
                if(n&1)//odd
                    ans= (m/2)*(n/2 + 1) + (m/2)*(n/2);
                else
                    ans= (m/2)*(n/2) + (m/2)*(n/2);
            }
            printf("Case %d: %d\n",++cas,ans);
        }
     
        return 0;
    }
     
