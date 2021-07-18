/*  Given an array of n positive integers and a number k.
 Find the minimum number of swaps required to bring all the numbers less than or equal to k together.*/

// C++ program to find minimum swaps required
// to club all elements less than or equals
// to k together
#include <iostream>
using namespace std;

int minSwap(int *arr, int n, int k);

// we will use here the approach of sliding window
// first count no. of elements less than or equal to k and store them in variable good
// now take another variable bad=0
// now iterate from i=0 to good (size of window) and count no. of elements graater than k in this window size and store it in bad
// initially now assign bad to ans(which will contain minimum no. of swaps) 
// now iterate two loops simultaneously one i=0 and other from j= good upto j<n
// inside this loop check if i th element of arr is greater than k is it so then decrease the bad by 1 
// as to decrease the window size
// now check if a jth element is greater than k then increase bad by 1
// now assign min of bad and ans to ans
// outside of loop return ans

int main()
{

    int t, n, k;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        cin >> k;
        cout << minSwap(arr, n, k) << "\n";
    }
    return 0;
}

int minSwap(int *arr, int n, int k)
{

    // Find count of elements which are
    // less than equals to k
    int good = 0;
    for (int i = 0; i < n; ++i)
        if (arr[i] <= k)
            ++good;

    // Find unwanted elements in current
    // window of size 'count'
    int bad = 0;
    for (int i = 0; i < good; ++i)
        if (arr[i] > k)
            ++bad;

    // Initialize answer with 'bad' value of
    // current window
    int ans = bad;
    for (int i = 0, j = good; j < n; ++i, ++j)
    {

        // Decrement count of previous window
        if (arr[i] > k)
            --bad;

        // Increment count of current window
        if (arr[j] > k)
            ++bad;

        // Update ans if count of 'bad'
        // is less in current window
        ans = min(ans, bad);
    }
    return ans;
}
