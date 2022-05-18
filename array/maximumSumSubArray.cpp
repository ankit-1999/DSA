#include <bits/stdc++.h>
using namespace std;

// kadane algorithm : find maximum sum subarray

int sumArray(int arr[],int l,int r) {
    int ans=0;
    for(int i=l;i<=r;i++)
    {
        ans+=arr[i];
    }
    return ans;
}


// brute force approach time complexity o(n^2)
int findmaxSumSubArray(int arr[],int n)
{
    int ans=0;
    if(n==1)
    {
        return arr[0];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            ans=max(ans,sumArray(arr,i,j));
        }
    }

    return ans;
}

// kadane algorithm  o(n)
int findmaxSumSubArray2(int arr[],int n)
{
    int ans=INT_MIN;
    int tmp=0;
    for(int i=0; i < n; i++)
    {
      tmp+=arr[i];
      ans=max(tmp,ans);
      if(tmp<0)  // if sum of any sub array is negative discard it
      {
          tmp=0;
      }
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    cout<<findmaxSumSubArray2(arr,n);

    return 0;
}