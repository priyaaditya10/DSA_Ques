class Solution
{
public:

// function to find missing number in an array
// use the xor method
// idea behind this is to first take xor of all the array elements
// then take xor of elements ranging from 0 to size of array
// then finally take xor of above two and we will get the missing number. 
// set x1=nums[0] i.e. first element of nums vector 
// and set x2=0;
// iterate through array from 1 to n-1 and take xor with x1 and assign to x1
// then iterate from 1 to n and take zor with x2 and assign to x2
// then finally take xor of x1 and x2 and assign to missing and return it
    int missingNumber(vector<int> &nums)
    {

        int missing;
        int n = nums.size();
        int x1 = nums[0];
        x2 = 0;

        for (int i = 1; i < n; i++)
        {
            x1 = x1 ^ nums[i];
        }

        for (int i = 1; i <= n; i++)
        {
            x2 = x2 ^ i;
        }

        missing = x1 ^ x2;

        return missing;
    }
};