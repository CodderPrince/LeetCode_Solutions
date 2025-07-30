class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.length();
        int m = str2.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1)); // Initializing all elements to -1
        
        // Filling the dp table using recursion
        int lcs_length = lcs(str1, str2, n, m, dp);
        
        string scs = "";
        int i = n, j = m;
        while (i > 0 && j > 0) {
            if (str1[i-1] == str2[j-1]) {
                scs += str1[i-1];
                i--;
                j--;
            } else if (dp[i][j-1] > dp[i-1][j]) {
                scs += str2[j-1];
                j--;
            } else {
                scs += str1[i-1];
                i--;
            }
        }
        while (i > 0) {
            scs += str1[i-1];
            i--;
        }
        while (j > 0) {
            scs += str2[j-1];
            j--;
        }
        reverse(scs.begin(), scs.end());
        return scs;
    }
    
    int lcs(string& str1, string& str2, int n, int m, vector<vector<int>>& dp) {
        if (n == 0 || m == 0)
            return 0;
        
        if (dp[n][m] != -1)
            return dp[n][m];
        
        if (str1[n-1] == str2[m-1])
            return dp[n][m] = 1 + lcs(str1, str2, n-1, m-1, dp);
        else
            return dp[n][m] = max(lcs(str1, str2, n-1, m, dp), lcs(str1, str2, n, m-1, dp));
    }
};
