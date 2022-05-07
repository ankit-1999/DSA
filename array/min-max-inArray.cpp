#include <bits/stdc++.h>
using namespace std;

// find minimum and maximum element in array that

struct Pair
{
    int min;
    int max;
};

// 1. using linear search O(N)
void getMinMax(int arr[], int n)
{
    int min = INT_MAX, mx = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
        else
        {
            mx = max(mx, arr[i]);
        }
    }
    cout << min << " " << mx;
}

// METHOD 2 (Tournament Method)
// Divide the array into two parts and compare the maximums and minimums of the two parts to get the maximum and the minimum of the whole array.

struct Pair getMinMax2(int arr[], int low, int high)
{
    struct Pair minmax, mml, mmr;
    if (low == high)  // when size of array is 1
    {
        minmax.min = arr[low];
        minmax.max = arr[low];
        return minmax;
    }
    else if (high == low + 1)  // when size of array is 2
    {
        if (arr[low] < arr[high])
        {
            minmax.min = arr[low];
            minmax.max = arr[high];
        }
        else
        {
            minmax.min = arr[high];
            minmax.max = arr[low];
        }
        return minmax;
    }
    else
    {
        int mid = (low + high) / 2;
        mml = getMinMax2(arr, low, mid);
        mmr = getMinMax2(arr, mid + 1, high);

        if (mml.min < mmr.min)
            minmax.min = mml.min;
        else
            minmax.min = mmr.min;

        // Compare maximums of two parts
        if (mml.max > mmr.max)
            minmax.max = mml.max;
        else
            minmax.max = mmr.max;

        return minmax;
    }
}

int main()
{
    int n;
    cin >> n;
    int array[n];
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }
    struct Pair tmp = getMinMax2(array, 0, n - 1);
    cout << tmp.min << " " << tmp.max << endl;

    return 0;
}