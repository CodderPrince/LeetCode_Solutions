class Solution {
public:
    static constexpr int MOD = 1e9 + 7;

    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> powersOfTwo;

        while (n > 0) {

            int largestPowerOfTwo = n & -n;

            powersOfTwo.emplace_back(largestPowerOfTwo);

            n -= largestPowerOfTwo;
        }

        vector<int> answer;

        for (auto& query : queries) {
            int start = query[0], end = query[1];
            long long product = 1;

            for (int i = start; i <= end; ++i) {
                product = (product * powersOfTwo[i]) % MOD;
            }

            answer.emplace_back(static_cast<int>(product));
        }

        return answer;
    }
};
