    #include<stdio.h>
    int main()
    {
        short tc;
        scanf("%hd",&tc);
        int loop1,loop2,Xlow,Ylow,Xhigh,Yhigh  ,Xc,Yc ,nc ;
        for(loop1 = 0;loop1<tc;loop1++)
        {
            scanf("%d %d %d %d",&Xlow,&Ylow,&Xhigh,&Yhigh);
     
            scanf("%d",&nc);
            printf("Case %d:\n",loop1+1);
            for(loop2=0;loop2<nc;loop2++)
            {
                scanf("%d %d",&Xc,&Yc);
                if( (Yc>Ylow && Yc < Yhigh )&& (Xc>Xlow && Xc< Xhigh) )
                {
     
     
                        printf("Yes\n");
     
     
                }
                else
                  {
     
                    printf("No\n");
                  }
            }
     
     
     
        }
     
     
     
        return 0;
    }
     
