class Solution {
public:
    int maxOrValue;
    int subsetCount;
    vector<int> numbers;

    int countMaxOrSubsets(vector<int>& nums) {
        numbers = nums;
        maxOrValue = 0;
        subsetCount = 0;

        for (int x : nums) {
            maxOrValue |= x;
        }

        dfs(0, 0);

        return subsetCount;
    }

    void dfs(int index, int currentOrValue) {

        if (index == numbers.size()) {

            if (currentOrValue == maxOrValue) {
                subsetCount++;
            }
            return;
        }

        dfs(index + 1, currentOrValue);

        dfs(index + 1, currentOrValue | numbers[index]);
    }
};
