class Solution {
public:
    int maxSum(vector<int>& nums) {
        set<int> unique(nums.begin(), nums.end());
        
        // If all numbers are negative, return the maximum among them
        int maxNegative = INT_MIN;
        int sum = 0;
        bool hasPositive = false;

        for (int num : unique) {
            if (num > 0) {
                sum += num;
                hasPositive = true;
            } else {
                maxNegative = max(maxNegative, num);
            }
        }

        return hasPositive ? sum : maxNegative;
    }
};
