class Solution {
public:
    int fibb(int n, int dp[]) {
        if (n == 0)
            return 0;
        else if (n == 1)
            return 1;
        if (dp[n] != -1)
            return dp[n];

        dp[n] = fibb(n - 1, dp) + fibb(n - 2, dp);
        return dp[n];
    }
    int fib(int n) {
        int dp[32];
        memset(dp, -1, sizeof(dp));
        return fibb(n, dp);
    }
};
