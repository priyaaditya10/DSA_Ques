// move zeros to end of array without using any extra space and mainting the order of non-zero elements'=

// approach used is place both left and right pointer on the first index
// check if nums[right] is a zero element and just increment the right pointer
// else if it is non-zero then swap nums[left] and num[right] and increement both pointers
//  do this thing till right<n
class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int n = nums.size();
        // to check if array contains 0 or only 1 element then just return it as it is
        if (n == 0 || n == 1)
            return;

        int left = 0, right = 0;
        while (right < n)
        {
            if (nums[right] == 0)
                ++right;
            else
            {
                swap(nums[left], nums[right]);
                ++left;
                ++right;
            }
        }
    }
};