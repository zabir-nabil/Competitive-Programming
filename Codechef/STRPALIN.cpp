bool str1mark[1000];
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
       string s1,s2;
       cin>>s1>>s2;
       memset(str1mark,false,sizeof(str1mark));
       for(int a=0;a<s1.length();a++)
        str1mark[(int)s1[a]] = true;
       int isPos = 0;
       for(int b=0;b<s2.length();b++)
       {
 
           if(str1mark[(int) s2[b] ] ==true)
           {
               isPos = 1;
               break;
 
           }
 
       }
 
        if(isPos)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
 
    return 0;
}