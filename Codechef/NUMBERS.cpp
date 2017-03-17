    #include<stdio.h>
    #include<stdlib.h>
    #include<string.h>
    void merge_sort(unsigned long long a[],char s[10000][100], int, int , int);
     
    int main()
    {
    int t,n,i;
    scanf("%d",&t);
    unsigned long long val;
    char s[10000][100];
    while(t--)
    {
    scanf("%d",&n);val=0;
    unsigned long long a[n],b[n];
    for(i=0;i<n;i++){
    scanf("%s%llu",s[i],&a[i]);b[i]=a[i];}
    merge_sort(a,s,0,n-1,n);
    for(i=0;i<n;i++)
    {
    if(i==0){
    	if(a[i]<a[i+1]){val=a[i];break;}}
    else if(i==n-1){
    	if(a[i]>a[i-1]){val=a[i];break;}}
    else if(a[i]>a[i-1] && a[i]<a[i+1]){val=a[i];break;}	
    }
    if(val==0)
    	printf("Nobody wins.\n");
    else
    	for(i=0;i<n;i++)
    		if(val==b[i]){
    			printf("%s\n",s[i]);break;}
    		
    }
    return 0;
    }
    void merge_sort(unsigned long long x[],char s[10000][100], int end, int start,int n) {
     int j = 0;
     const int size = start - end + 1;
     int mid  = 0;
     int mrg1 = 0;
     int mrg2 = 0;
     int executing[n];
     
     if(end == start)
      return;
     
     mid  = (end + start) / 2;
     
     merge_sort(x,s, end, mid,n);
     merge_sort(x,s,mid + 1, start,n);
     
     for(j = 0; j < size; j++)
      executing[j] = x[end + j];
     
     mrg1 = 0;
     mrg2 = mid - end + 1;
     
     for(j = 0; j < size; j++) {
      if(mrg2 <= start - end)
       if(mrg1 <= mid - end)
        if(executing[mrg1] > executing[mrg2]){
         x[j + end] = executing[mrg2++]; }
        else{
         x[j + end] = executing[mrg1++]; }
       else{
        x[j + end] = executing[mrg2++];}
      else{
       x[j + end] = executing[mrg1++]; }
     }
 }