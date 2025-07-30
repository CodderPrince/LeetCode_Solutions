class Solution {
public:
    int dp[1001][1001]; // Global array
    
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.length(); // Change here
        int n = str2.length(); // Change here
        
        // Initializing dp array to -1
        memset(dp, -1, sizeof(dp));
        
        // Filling the dp table using recursion
        int lcs_length = lcs(str1, str2, m, n); // Change here
        
        string scs = "";
        int i = m, j = n; // Change here
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
    
    int lcs(string& str1, string& str2, int m, int n) { // Change here
        if (m == 0 || n == 0) // Change here
            return 0;
        
        if (dp[m][n] != -1) // Change here
            return dp[m][n]; // Change here
        
        if (str1[m-1] == str2[n-1]) // Change here
            return dp[m][n] = 1 + lcs(str1, str2, m-1, n-1); // Change here
        else
            return dp[m][n] = max(lcs(str1, str2, m-1, n), lcs(str1, str2, m, n-1)); // Change here
    }
};
