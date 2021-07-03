// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, int s)
    {
        vector<int> result;
        bool flag = false;
        unsigned long long current_sum = 0;
        int start = 0, last = 0;
       // initializing start and last=0 and then traversing from begining if current sum is less than sum then keep on adding elements
       // else if current sum is greater then last=i and  while current sum is greater then sum and start<last keep on subtrating elemnts from last until 
       // currentsum=sum and if it happens then push start+1 and last+1 position in vecotr and set flag as true and break the loop
        for (int i = 0; i < n; i++)
        {

            current_sum = current_sum + arr[i];

            if (current_sum >= s)
            {
                last = i;
                while (current_sum > s && start < last)
                {
                    current_sum = current_sum - arr[start];
                    ++start;
                }
                if (current_sum == s)
                {
                    result.push_back(start + 1);
                    result.push_back(last + 1);
                    flag = true;
                    break;
                }
            }
        }

        if (flag == false)
        {
            result.push_back(-1);
        }

        return result;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        long long s;
        cin >> n >> s;
        int arr[n];

        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        vector<int> res;
        res = ob.subarraySum(arr, n, s);

        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }
    return 0;
} // } Driver Code Ends