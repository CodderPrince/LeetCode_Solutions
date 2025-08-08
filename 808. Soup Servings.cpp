class Solution {
public:
    double soupServings(int n) {

        double probabilityCache[200][200] = {0.0};

        function<double(int, int)> calculateProbabilities =
            [&](int soupA, int soupB) -> double {
            if (soupA <= 0 && soupB <= 0)
                return 0.5;
            if (soupA <= 0)
                return 1;
            if (soupB <= 0)
                return 0;

            if (probabilityCache[soupA][soupB] > 0)
                return probabilityCache[soupA][soupB];

            double probability =
                0.25 * (calculateProbabilities(soupA - 4, soupB) +
                        calculateProbabilities(soupA - 3, soupB - 1) +
                        calculateProbabilities(soupA - 2, soupB - 2) +
                        calculateProbabilities(soupA - 1, soupB - 3));
            probabilityCache[soupA][soupB] = probability;
            return probability;
        };

        if (n > 4800) {
            return 1;
        }

        return calculateProbabilities((n + 24) / 25, (n + 24) / 25);
    }
};
