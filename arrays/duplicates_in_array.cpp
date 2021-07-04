/*Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.*/


// If we are allowed to use extra space 
// we will create an unordered_map and store elements of array with their frequencies
// the we will iterate through the map if frequency is>1 then return that element

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {

        int n = nums.size();
        int element;
        unordered_map<int, int> freq;

        for (int i = 0; i < n; i++)
        {
            freq[nums[i]]++;
        }
        unordered_map<int, int>::iterator itr;
        for (itr = freq.begin(); itr != freq.end(); itr++)
        {
            if (itr->second > 1)
            {
                element = itr->first;
            }
        }

        return element;
    }
};



// If we are not allowed to use extra space
// iterate through array
// for each element check nums[abs[nums(i)]-1]<0 (if it is negative ) then return that element
// else set nums[abs(nums[i])-1] *= -1; ( to set it as negative)

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            if (nums[abs(nums[i]) - 1] < 0)
            {
                return abs(nums[i]);
            }
            else
            {
                nums[abs(nums[i]) - 1] *= -1;
            }
        }

        return 0;
    }
};