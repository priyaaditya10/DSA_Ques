/*You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future 
to sell that stock.Return the maximum profit you can achieve from this transaction. 
If you cannot achieve any profit, return 0. */

// if we have to buy and sell only one stock

// aprroach is to first store first element of prices array in min_so_far (to buy stock)
// now set max_profit=0 and profit=0
// now iterate through the prices array
// now calculate the min between min_so_far and ith element and assign to min_sofar
// now calculate profit as prices[i]-min_so_far
// and calculate the max between max_profit and profit and assign to max_profit
// outside of loop return max_profit


class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        // to store the minimum value so far (to buy)
        int min_so_far = prices[0];
        // to store max profit so far
        int max_profit = 0;

        int profit = 0;

        for (int i = 0; i < prices.size(); i++)
        {
            min_so_far = min(min_so_far, prices[i]);
            profit = prices[i] - min_so_far;

            max_profit = max(profit, max_profit);
        }

        return max_profit;
    }
};