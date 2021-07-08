// A C++ program to find if there is a zero sum
// subarray


#include <bits/stdc++.h>
using namespace std;

// Approach is to first create a boolean variable flag and assign its value as flase initially
// also set sum=0 and create a unordered_map m which will contain sum of array elements upto ith index
// now iterrate through array and calculate sum by adding ith array element
// check if sum is 0 or map already contain this sum (because if map already contains this sum value that means sum value has increased
// and ultimstely decreased causing intermediate subarray sum 0 ) or if array element is itself 0 (beacuse each element is also a subarray in itlsef)
// if any of these condiditions is true then set flag=true and break
// else set the frequency of that sum in map as 1
// and then outside loop return flag

class Solution
{
public:
    
    //Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(int arr[], int n)
    {
        bool flag = false;
        unordered_map<int, int> m;
        int sum = 0;

        for (int i = 0; i < n; i++)
        {
            sum = sum + arr[i];
            if (sum == 0 || m[sum] || arr[i] == 0)
            {
                flag = true;
                break;
            }

            else
            {
                m[sum] = 1;
            }
        }

        return flag;
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
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution obj;
        if (obj.subArrayExists(arr, n))
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
} 