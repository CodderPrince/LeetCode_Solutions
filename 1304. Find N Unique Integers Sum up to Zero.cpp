class Solution {
public:
    vector<int> sumZero(int n) {

        vector<int> result(n);

        int index = 0;
        for (int i = 1; i <= n / 2; ++i) {
            result[index++] = i;
            result[index++] = -i;
        }

        return result;
    }
};
