/* You are given an array prices where prices[i] is the price of a given stock on the ith day.
Find the maximum profit you can achieve. You may complete as many transactions as you like 
(i.e., buy one and sell one share of the stock multiple times).
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
*/

// approach is to just iterate from i=1 to n-1 and 
// compare if ith price if greater than the i-t th price, if it is true then just find diff and add it to profit
// outside of loop return profit

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {

        int profit = 0;

        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] > prices[i - 1])
            {
                profit += (prices[i] - prices[i - 1]);
            }
        }

        return profit;
    }
};