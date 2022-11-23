// Source: https://leetcode.com/problems/coin-change/

/*************************************************************************************** 
 *
 * You are given an integer array coins representing coins of different denominations
 * and an integer amount representing a total amount of money. 
 * Return the fewest number of coins that you need to make up that amount. If that 
 * amount of money cannot be made up by any combination of the coins, return -1;
 * 
 * Note: Assume you have an infinite number of each kind of coin.
 
 * Example 1:
 * Input: coins = [1, 2, 5], amount = 11
 * Output: 3 
 * Explanation: (11 = 5 + 5 + 1)
 * 
 * Example 2:
 * Input: coins = [2], amount = 3
 * Output: -1.
 *
 * Example 3:
 * Input: coins = [1], amount = 0
 * Output: 0
 ***************************************************************************************/
 
// Solution using bottom up dynamic programming
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int ans = 0;
        
        // initialize array to amount+1 because dp starts from 0, the value could be anything as long as it is greater than amount 
        vector<int> dp(amount+1, INT_MAX-1);
        
        // initialize first element to 0 because amount 0 require 0 coins
        dp[0] = 0;
        
        // Loop through amount from 1 to amount
        for (int i=1; i<=amount; i++) {
            // For each amount, check each coin and get the result
            for (int j=0; j<coins.size(); j++) {
                // if current coin is less than the current amount, then can proceed. Eg. if amount is 3, and coint is 5, there is no way 5 will add up to 3.
                if (coins[j] <= i) {
                    // Get minimum current amount (dp[i]) by comparing the original value and 1 (the current coin that is using) plus the remain coin
                    // Remaining coin can get by dp[current amount minus current coin]
                    // Eg. for amount 5, and coin 3, we can 1 (the coin 3) plus the remaining (dp[2], 5-3 = 2, dp[2] is already calculated)
                    dp[i] = min(dp[i], 1 + dp[i-coins[j]]);
                } 
            }
        }
        
        
        return dp[amount] == INT_MAX-1 ? -1 : dp[amount];
    }
};
