class Solution {
public:
    bool reorderedPowerOf2(int n) {

        vector<int> originalDigitsCount = countDigits(n);

        for (int i = 1; i <= 1e9; i <<= 1) {

            if (originalDigitsCount == countDigits(i))
                return true;
        }
        return false;
    }

    vector<int> countDigits(int n) {
        vector<int> digitCount(10, 0);
        while (n != 0) {

            digitCount[n % 10]++;

            n /= 10;
        }
        return digitCount;
    }
};
