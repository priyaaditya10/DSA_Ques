/* Given array A[] of integers, the task is to complete the function findMaxDiff 
which finds the maximum absolute difference between nearest left and right smaller element of every element in array.
If the element is the leftmost element, nearest smaller element on left side is considered as 0.
 Similarly if the element is the rightmost elements,
 smaller element on right side is considered as 0.*/


#include <bits/stdc++.h>
using namespace std;



class Solution
{
public:
    void leftSmaller(int arr[], int n, int SE[])
    {
        // Create an empty stack
        stack<int> S;

        // Traverse all array elements
        // compute nearest smaller elements of every element
        for (int i = 0; i < n; i++)
        {
            // Keep removing top element from S while the top
            // element is greater than or equal to arr[i]
            while (!S.empty() && S.top() >= arr[i])
                S.pop();

            // Store the smaller element of current element
            if (!S.empty())
                SE[i] = S.top();

            // If all elements in S were greater than arr[i]
            else
                SE[i] = 0;

            // Push this element
            S.push(arr[i]);
        }
    }

    /*You are required to complete this method */
    int findMaxDiff(int arr[], int n)
    {
        int LS[n]; // To store left smaller elements

        // find left smaller element of every element
        leftSmaller(arr, n, LS);

        // find right smaller element of every element
        // first reverse the array and do the same process
        int RRS[n]; // To store right smaller elements in
                    // reverse array
        reverse(arr, arr + n);
        leftSmaller(arr, n, RRS);

        // find maximum absolute difference b/w LS & RRS
        // In the reversed array right smaller for arr[i] is
        // stored at RRS[n-i-1]
        int result = -1;
        for (int i = 0; i < n; i++)
            result = max(result, abs(LS[i] - RRS[n - 1 - i]));

        // return maximum difference b/w LS & RRS
        return result;
    }
};


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution ob;
        cout << ob.findMaxDiff(a, n) << endl;
    }
    return 0;
}

