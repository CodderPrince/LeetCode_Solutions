class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int maxFruits = 0;
        int currentSum = 0;

        for (int i = 0, j = 0; j < fruits.size(); ++j) {
            int positionJ = fruits[j][0];
            int fruitCountJ = fruits[j][1];
            currentSum += fruitCountJ;

            while (i <= j && positionJ - fruits[i][0] +
                                     min(abs(startPos - fruits[i][0]),
                                         abs(startPos - positionJ)) >
                                 k) {
                currentSum -= fruits[i][1];
                i++;
            }

            maxFruits = max(maxFruits, currentSum);
        }

        return maxFruits;
    }
};
