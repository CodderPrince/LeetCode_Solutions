#include <unordered_map>

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int windowStart;
        int windowEnd;
        int finalMax = 0;
        std::unordered_map<int, int> u1;

        for (windowStart = 0, windowEnd = 0; windowEnd < fruits.size(); windowEnd++) {
            u1[fruits[windowEnd]]++;

            while (u1.size() > 2) {
                u1[fruits[windowStart]]--;
                if (u1[fruits[windowStart]] == 0) {
                    u1.erase(fruits[windowStart]);
                }
                windowStart++;
            }
            finalMax = max(finalMax, windowEnd - windowStart + 1);
        }
        return finalMax;
    }
};
