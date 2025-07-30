class Solution {
public:
    int longestSubarray(std::vector<int>& nums) {

        int maxValue = *std::max_element(nums.begin(), nums.end());

        int longestSubarrayLength = 0, currentSubarrayLength = 0;

        for (int value : nums) {

            if (value == maxValue) {

                ++currentSubarrayLength;

                longestSubarrayLength =
                    std::max(longestSubarrayLength, currentSubarrayLength);
            } else {

                currentSubarrayLength = 0;
            }
        }

        return longestSubarrayLength;
    }
};
