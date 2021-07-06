/*  Given an array of N integers, and an integer K,
 find the number of pairs of elements in the array whose sum is equal to K.*/




#include <bits/stdc++.h>
using namespace std;


// Approach is to create an unordered map and initialize count=0 
// now iterarte through array and find complement of each array element with target (k)
// now check if freq of complement element is 0 in map then insert that ith element in map and increase its frequency with one
// else if its frequency is not 0 then add its frequency to count and insert that ith element in map and increase its frequency.

class Solution
{
public:
    int getPairsCount(int arr[], int n, int k)
    {
        unordered_map<int, int> m;
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            int complement = k - arr[i];
            if (m[complement] == 0)
            {
                m[arr[i]]++;
            }
            else
            {
                count += m[complement];
                m[arr[i]]++;
            }
        }

        return count;
    }
};



int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getPairsCount(arr, n, k);
        cout << ans << "\n";
    }

    return 0;
} 