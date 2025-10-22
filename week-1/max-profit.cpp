//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/


// Brute Force Approach
// Time Complexity: O(n^2)
// Space Complexity: O(1)
#include<iostream>
#include <vector>
#include <climits>
using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        for (int i = 0; i < prices.size(); i++) {
            for (int j = i + 1; j < prices.size(); j++) {
                int profit = prices[j] - prices[i];
                if (profit > maxProfit) {
                    maxProfit = profit;
                }
            }
        }
        return maxProfit;
    }
};

/*
Optimized Approach
Time Complexity: O(n)
Space Complexity: O(1)
Here we keep track of the minimum price seen so far and calculate the potential profit at each price.
If the potential profit is greater than the maximum profit recorded, we update the maximum profit.
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;
        for (int price : prices) {  
            minPrice = min(minPrice, price);             
            maxProfit = max(maxProfit, price - minPrice); 
        }
        return maxProfit;
    }
};
