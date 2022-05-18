#include<bits/stdc++.h>
using namespace std;

// contain duplicate : to check wheather a duplicate of element is present or not 

// brute force approach o(n^2)

bool containsDuplicate(int arr[],int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[j] == arr[i])
            {
                return true;
            }
        }
    }
    return false;
}

// sort the array first then compare o(nlogn)

bool containsDuplicate2(int arr[],int n)
{
   
    sort(arr,arr+n);
    
    for(int i=0;i<n-1;i++)
    {
        if(arr[i] == arr[i+1])
        {
            return true;
        }
    }
    return false;
}


int main()
{
    int n ;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    cout<<containsDuplicate2(arr,n);

    return 0;
}