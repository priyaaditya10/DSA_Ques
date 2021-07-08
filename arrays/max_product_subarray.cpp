
/*Given an array Arr that contains N integers (may be positive, negative or zero).
 Find the product of the maximum product subarray. */

#include <bits/stdc++.h>

using namespace std;


class Solution
{
public:
    // Function to find maximum product subarray
    long long maxProduct(int *arr, int n)
    {
        // Variables to store maximum and minimum
        // product till ith index.
        long long minVal = arr[0];
        long long maxVal = arr[0];

        long long maxProduct = arr[0];

        for (int i = 1; i < n; i++)
        {

            // When multiplied by -ve number,
            // maxVal becomes minVal
            // and minVal becomes maxVal.
            if (arr[i] < 0)
                swap(maxVal, minVal);

            // maxVal and minVal stores the
            // product of subarray ending at arr[i].
            maxVal = max((long long)arr[i], maxVal * arr[i]);
            minVal = min((long long)arr[i], minVal * arr[i]);

            // Max Product of array.
            maxProduct = max(maxProduct, maxVal);
        }

        // Return maximum product found in array.
        return maxProduct;
    }
};


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}