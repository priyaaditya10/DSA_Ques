/* Given two sorted arrays arr1[] and arr2[] of sizes n and m in non-decreasing order. 
Merge them in sorted order without using any extra space. 
Modify arr1 so that it contains the first N elements and modify arr2 so that it contains the last M elements.*/


#include <bits/stdc++.h>
using namespace std;

// approach is to take 3 pointers i,j and k
// i pointing to index 0 of arr1 , j pointing to index 0 of arr2 and k pointing to last index(n-1) of arr1
// now iterate through both arrays until i<=k and j<m where m is size of arr2
// check if arr1[i]<arr2[j] if it is true then do nothing and just increment pointer i by 1
// else swap kth element of arr1 with jth element of arr2 and increment pointer j by 1 and decrement pointer k by 1
// and then outside of loop sort both arrays

class Solution
{
public:
    //Function to merge the arrays.
    void merge(long long arr1[], long long arr2[], int n, int m)
    {
        int i = 0, j = 0, k = n - 1;

        while (i <= k && j < m)
        {
            if (arr1[i] < arr2[j])
            {
                i++;
            }

            else
            {
                swap(arr1[k--], arr2[j++]);
            }
        }

        sort(arr1, arr1 + n);
        sort(arr2, arr2 + m);
    }
};



int main()
{

    int T;
    cin >> T;

    while (T--)
    {
        int n, m;
        cin >> n >> m;

        long long arr1[n], arr2[m];

        for (int i = 0; i < n; i++)
        {
            cin >> arr1[i];
        }

        for (int i = 0; i < m; i++)
        {
            cin >> arr2[i];
        }
        Solution ob;
        ob.merge(arr1, arr2, n, m);

        for (int i = 0; i < n; i++)
            cout << arr1[i] << " ";

        for (int i = 0; i < m; i++)
            cout << arr2[i] << " ";

        cout << endl;
    }

    return 0;
}
