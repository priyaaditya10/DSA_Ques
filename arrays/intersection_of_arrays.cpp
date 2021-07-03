// program to find intersection of two sorted arrays and also removing duplicated elements

// approach is create a new vector to store result
// create two sets s1 and s2 store elements of nums1 in s1 and elements of nums2 in s2 now both set s1 and s2 will contain distinct elements
// now set an iterator and iterate from begin to end of set s1
// now find element of s2 in s1 if their exists then just push that element in result vector

class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {

        vector<int> result;
        set<int> s1, s2;

        for (int i = 0; i < nums1.size(); i++)
        {
            s1.insert(nums1[i]);
        }

        for (int j = 0; j < nums2.size(); j++)
        {
            s2.insert(nums2[j]);
        }

        set<int>::iterator itr;

        for (itr = s1.begin(); itr != s1.end(); itr++)
        {
            if (s2.find(*itr) != s2.end())
            {
                result.push_back(*itr);
            }
        }

        return result;
    }
};