class Solution {
public:
    bool wild(int i, int j, const string &p, const string &t, vector<vector<int>> &dp) {
        if (i < 0 && j < 0) {
            return true;
        }
        if (i < 0 && j >= 0) {
            return false;
        }
        if (j < 0 && i >= 0) {
            for (int k = 0; k <= i; k++) {
                if (p[k] != '*') {
                    return false;
                }
            }
            return true;
        }

        if (dp[i][j] != 0) {
            return dp[i][j] == 1;
        }

        if (p[i] == '?' || p[i] == t[j]) {
            dp[i][j] = wild(i - 1, j - 1, p, t, dp) ? 1 : -1;
        } else if (p[i] == '*') {
            dp[i][j] = (wild(i, j - 1, p, t, dp) || wild(i - 1, j, p, t, dp)) ? 1 : -1;
        } else {
            dp[i][j] = -1;
        }

        return dp[i][j] == 1;
    }

    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        return wild(n - 1, m - 1, p, s, dp);
    }
};
