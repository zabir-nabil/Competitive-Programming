#include <bits/stdc++.h>

using namespace std;
int arr[100005];
int min_ans[100005];
int min_idx[100005];
int ans[100005];
int bin_s(int i,int j,int k)
{
    int b = i, e = j;

    while(b<=e)
    {
        int mid = (b+e)/2;

        if(min_ans[mid]<k
           && min_ans[mid+1]>=k)
        {
            return min_idx[mid];
        }
        else if(min_ans[mid]<k)
        {
            b = mid+1;
        }
        else
        {
            e = mid-1;
        }
    }

    return -1;


}
int main()
{
    int n;
    while(cin>>n)
    {
        for(int i=1; i<=n; i++)
        {
            cin>>arr[i];
        }
        min_ans[n] = arr[n];
        min_idx[n] = n;
        for(int i=n-1; i>=1; i--)
        {

            if(min_ans[i+1]<=arr[i])
            {
                min_ans[i] = min_ans[i+1];
                min_idx[i] = min_idx[i+1];
            }
            else
            {
                min_ans[i] = arr[i];
                min_idx[i] = i;
            }
        }
/*
        for(int i=1;i<=n;i++)
        {
            cout<<min_ans[i]<<" ";
        }

        cout<<endl;

        for(int i=1;i<=n;i++)
        {
            cout<<min_idx[i]<<" ";
        }

        cout<<endl;
*/
        min_ans[n+1] = 9999999999;


        for(int i=1; i<=n; i++)
        {
            if(i==n)
                ans[i] = -1;

            else
            {
                int tmp = bin_s(i+1,n,arr[i]);
                if(tmp==-1)
                    ans[i] = -1;
                else
                    ans[i] = (tmp-i-1);
            }
        }

        for(int i=1;i<=n;i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;



    }
    return 0;
}
