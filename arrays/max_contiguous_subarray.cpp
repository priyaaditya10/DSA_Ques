// Also known as Kadanes's algo

#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    int maxSubarraySum(int arr[], int n)
    {

        int max_so_far = INT_MIN; // initialize max_so_far with INT_MIN
        int max_end_here = 0; // initialize max_end_here with 0

        for (int i = 0; i < n; i++)
        {
            // continuously add each array eleemnt to max_end here and compare with max_so_far is it is greater then assign to max_so _far
            max_end_here = max_end_here + arr[i];
            if (max_so_far < max_end_here)
            {
                max_so_far = max_end_here;
            }

            if (max_end_here < 0)
            {
                max_end_here = 0;
            }
        }

        return max_so_far;
    }
};


int main()
{
    int t, n;

    cin >> t;   //input testcases
    while (t--) //while testcases exist
    {

        cin >> n; //input size of array

        int a[n];

        for (int i = 0; i < n; i++)
            cin >> a[i]; //inputting elements of array

        Solution ob;

        cout << ob.maxSubarraySum(a, n) << endl;
    }
}
