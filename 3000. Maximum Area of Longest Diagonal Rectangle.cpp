class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxArea = 0;
        int maxDiagonalSq = 0;
        for (auto& dimension : dimensions) {
            int length = dimension[0];
            int width = dimension[1];
            int diagonalSq = length * length + width * width;

            if (maxDiagonalSq < diagonalSq) {
                maxDiagonalSq = diagonalSq;
                maxArea = length * width;

            } else if (maxDiagonalSq == diagonalSq) {
                maxArea = max(maxArea, length * width);
            }
        }

        return maxArea;
    }
};
