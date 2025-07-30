class Solution {
public:
    // memoization
    // memoization
    int dp[10010];

    // user defined function
    int func(vector<int>& coins, int amount) {
        // base case
        /*
        for 0 coins no need to any coins
        */

        if (amount == 0) {
            return 0;
        }

        // check dp result that is before calculated or not
        if (dp[amount] != -1) {
            return dp[amount];
        }

        // assume ans is long integer
        int ans = INT_MAX;

        for (int coin : coins) {
            // if negative then ignore
            if (amount - coin >= 0) {
                ans = min(ans + 0LL, func(coins, amount - coin) + 1LL);
            }
        }
        return dp[amount] = ans;
    }

    // leetcode function
    int coinChange(vector<int>& coins, int amount) {
        memset(dp, -1, sizeof(dp)); // initialize all arrays by -1
        int ans = func(coins, amount);

        return ans == INT_MAX ? -1 : ans;
    }
};
