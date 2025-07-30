class Solution {
public:
    int dp[1001][1001];
    int lps(string& s, int i, int j) {
        if (i > j) {
            return 0;
        }
        if (i == j) {
            return 1;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        if (s[i] == s[j]) {
            return dp[i][j] = 2 + lps(s, i + 1, j - 1);
        } else

        {
            return dp[i][j] = max(lps(s, i + 1, j), lps(s, i, j - 1));
        }
    }
    int longestPalindromeSubseq(string s)

    {
        memset(dp, -1, sizeof(dp));
        return lps(s, 0, s.length() - 1);
    }
};
