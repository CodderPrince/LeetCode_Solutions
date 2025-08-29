class Solution {
public:
    long long flowerGame(int n, int m) {

        long long length_rounded_up = (n + 1) / 2;

        long long width_rounded_up = (m + 1) / 2;

        long long length_rounded_down = n / 2;

        long long width_rounded_down = m / 2;

        long long total_pairs = length_rounded_up * width_rounded_down +
                                length_rounded_down * width_rounded_up;

        return total_pairs;
    }
};
