#include<bits/stdc++.h>
using namespace std;

/*   
    You are given an array prices where prices[i] is the price of a given stock on the ith day.
    You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
    Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

*/

int bestTime(int arr[],int n)
{
    int buy=arr[0];
    int profit=0;
    for(int i=1;i<n;i++)
    {
        if(buy<arr[i])
        {
            profit=max(profit,arr[i]-buy);
        }
        else
        {
            buy=arr[i];
        }
        

    }
    return profit;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<bestTime(arr,n);
    return 0;
}