//C++ 	0.000 	1088   Accepted    
 #include<stdio.h>
    int main()
    {
        short tc=0;
        scanf("%hd",&tc);
        for(short loop = 0 ; loop<tc ; loop++)
       {
           short a;
           scanf("%hd",&a);
           if(a<10)
           printf("%hd %hd\n",0,a-0);
           else
           {
               printf("%hd %hd\n",10,a-10);
           }
     
       }
     
        return 0;
    }
