/* problem is to rearrange elements of an array as first positive then negative and so on using O(1) space only*/

// approach is to first separate all the negative elements to right end and positive to left end
// after this our left pointer will be pointing to first negative element
// take another pointer k point it to k=1
// iterate through array
// swap nums[left] with nums[k] and increment k by 2 and left by 1
// until left==n

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void rearrange_array(vector<int> &nums)
    {
        int n = nums.size();

        if (n == 1 || n == 0)
        {
            return;
        }

        int left = 0, right = 0;

        while (right < n)
        {
            if (nums[right] < 0)
            {
                right++;
            }
            else
            {
                swap(nums[left], nums[right]);
                left++;
                right++;
            }
        }

        int k = 1;
        for (int i = 1; i < n; i++)
        {
            if (left != n)
            {
                swap(nums[k], nums[left]);
                left++;
                k = k + 2;
            }
        }
    }
};

int main()
{

    int n, num;
    cout << "\n Enter size";
    cin >> n;

    vector<int> nums;

    for (int i = 0; i < n; i++)
    {
        cin >> num;
        nums.push_back(num);
    }
    cout << endl;

    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }

    Solution ob;
    ob.rearrange_array(nums);
    cout << endl;

    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }

    return 0;
}