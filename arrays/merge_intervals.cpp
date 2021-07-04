/*Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals,
 and return an array of the non-overlapping intervals that cover all the intervals in the input.*/

// Approach is first  create a res vector of interger vector 
//then check if intervals vector is empty or not
// then sort the intervals vector according to start time
// then first push intervals[0] (first interval) in res vector
// now iterate from i=0 to n-1
// if the end time of previous interval in res vector is less than that of intervals[i][0] (start time of ith interval)
// then just push that ith interval in res vector
// else find the max of end time of previous interval in res vector and end time of ith interval and assign it to res.back()[1] (end time of interval in res)
class Solution
{
public:
    static bool compare(vector<int> &a, vector<int> &b)
    {
        return a[0] < b[0]; // comparing starting time of a and b vector
    }

    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {

        vector<vector<int>> res;
        int n = intervals.size();

        if (intervals.empty())
        {
            return res;
        }

        sort(intervals.begin(), intervals.end(), compare); // sorting interval vector on basis of compare function

        res.push_back(intervals[0]);

        for (int i = 0; i < n; i++)
        {
            if (res.back()[1] < intervals[i][0])
            {
                res.push_back(intervals[i]);
            }

            else
            {
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            }
        }

        return res;
    }
};