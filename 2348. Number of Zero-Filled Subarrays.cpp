class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long answer = 0;
        int zeroCount = 0;

        for (int value : nums) {

            zeroCount = (value != 0) ? 0 : zeroCount + 1;

            answer += zeroCount;
        }

        return answer;
    }
};
