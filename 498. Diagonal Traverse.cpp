class Solution {
public:
    std::vector<int> findDiagonalOrder(std::vector<std::vector<int>>& matrix) {
        int rows = matrix.size(), columns = matrix[0].size();
        std::vector<int> result;
        std::vector<int> diagonalElements;

        for (int diag = 0; diag < rows + columns - 1; ++diag) {

            int i = diag < columns ? 0 : diag - columns + 1;
            int j = diag < columns ? diag : columns - 1;

            while (i < rows && j >= 0) {
                diagonalElements.push_back(matrix[i++][j--]);
            }

            if (diag % 2 == 0) {
                std::reverse(diagonalElements.begin(), diagonalElements.end());
            }

            for (int value : diagonalElements) {
                result.push_back(value);
            }

            diagonalElements.clear();
        }

        return result;
    }
};
