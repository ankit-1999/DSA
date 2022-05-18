#include <bits/stdc++.h>
using namespace std;

//  to reverse an array 

void printArray(int arr[],int n)
{
    for(int i=0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
}

void reverse(int arr[],int left,int right)
{
    if(left>=right)
    {
        return;
    }
    swap(arr[left],arr[right]);
    reverse(arr,left+1,right-1);
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    reverse(arr,0,n-1);
    printArray(arr,n);

    return 0;
}