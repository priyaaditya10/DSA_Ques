/* Given an array A[ ] of positive integers of size N,
 where each value represents the number of chocolates in a packet. 
 Each packet can have a variable number of chocolates. 
 There are M students, the task is to distribute chocolate packets among M students such that :
1. Each student gets exactly one packet.
2. The difference between maximum number of chocolates given to a student and 
    minimum number of chocolates given to a student is minimum.*/

// here i+m-1 help us to point at mth element of subarray 

#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
    long long findMinDiff(vector<long long> a, long long n, long long m)
    {

        // Sort the given packets
        sort(a.begin(), a.end());

        long long start = 0, end = 0;
        // Largest number of chocolates
        long long mind = LONG_LONG_MAX;

        // Find the subarray of size m such that
        // difference between last (maximum in case
        // of sorted) and first (minimum in case of
        // sorted) elements of subarray is minimum.
        for (long long i = 0; i + m - 1 < n; i++)
        {
            long long diff = a[i + m - 1] - a[i];
            if (mind > diff)
            {
                mind = diff;
                start = i;
                end = i + m - 1;
            }
        }
        return a[end] - a[start];
    }
};


int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        vector<long long> a;
        long long x;
        for (long long i = 0; i < n; i++)
        {
            cin >> x;
            a.push_back(x);
        }

        long long m;
        cin >> m;
        Solution ob;
        cout << ob.findMinDiff(a, n, m) << endl;
    }
    return 0;
} 