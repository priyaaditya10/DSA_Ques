/*Given an array arr[] denoting heights of N towers and a positive integer K, 
you have to modify the height of each tower either by increasing or decreasing them by K only once. 
After modifying, height should be a non-negative integer. 
Find out what could be the possible minimum difference of the height of shortest and longest towers after
you have modified each tower.*/



#include <bits/stdc++.h>
using namespace std;

// approach is to first sort the array of heights
// the initially the difference between max and min heights will be last element - first element store it in a variable diff
// Set smallest to the first element of array + k and largest to last element -k of the array.
// traverse from i=0 to n-2
// now just find min of smallest element and i+1 th element -k  and assign to min_element
// find max of largest and i th element+k  and assign it to max_element
// now check once if min_element is not a non-negative element if it so than continue
// and then find min of diff and max_element - min_element and assign to diff and outside of loop return diff

class Solution
{
public:
    int getMinDiff(int arr[], int n, int k)
    {

        sort(arr, arr + n);

        int diff = arr[n - 1] - arr[0];
        int smallest = arr[0] + k;
        int largest = arr[n - 1] - k;

        int min_element, max_element;

        for (int i = 0; i < n - 1; i++)
        {
            min_element = min(smallest, arr[i + 1] - k);
            max_element = max(largest, arr[i] + k);

            if (min_element < 0) // minimize the heights I remove this condition as it can accept negative values
                continue;

            diff = min(diff, max_element - min_element);
        }

        return diff;
    }
    };

    
    int main()
    {
        int t;
        cin >> t;
        while (t--)
        {
            int n, k;
            cin >> k;
            cin >> n;
            int arr[n];
            for (int i = 0; i < n; i++)
            {
                cin >> arr[i];
            }
            Solution ob;
            auto ans = ob.getMinDiff(arr, n, k);
            cout << ans << "\n";
        }
        return 0;
    }