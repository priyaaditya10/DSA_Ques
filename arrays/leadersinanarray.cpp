// { Driver Code Starts
// C++ program to remove recurring digits from
// a given number
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    //Function to find the leaders in the array. print a number if all the numbers on its right are
    // less than that number and always print the rightmost element
    // create a vector named result
    // set max_right with last element and push it in vector then iterate from second last element to first element
    // and check if a[i]>=max_right if it is so then set max_right=a[i] and push it in vector
    // outside of loop reverse the vector and return it
public:
    vector<int> leaders(int a[], int n)
    {
        vector<int> result;
        int max_right = a[n - 1];

        result.push_back(max_right);
        for (int i = n - 2; i >= 0; i--)
        {
            if (a[i] >= max_right)
            {
                max_right = a[i];
                result.push_back(a[i]);
            }
        }

        reverse(result.begin(), result.end());
        return result;
    }
};

// { Driver Code Starts.

int main()
{
    long long t;
    cin >> t; //testcases
    while (t--)
    {
        long long n;
        cin >> n; //total size of array

        int a[n];

        //inserting elements in the array
        for (long long i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution obj;
        //calling leaders() function
        vector<int> v = obj.leaders(a, n);

        //printing elements of the vector
        for (auto it = v.begin(); it != v.end(); it++)
        {
            cout << *it << " ";
        }

        cout << endl;
    }
}
// } Driver Code Ends