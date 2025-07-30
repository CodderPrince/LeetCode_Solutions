class Solution {
public:
    int fib(int n) {
        // base case
        if (n == 0) {
            return 0;
        } else if (n == 1) {
            return 1;
        }

        int a = 0;
        int b = 1;
        int c = 1;

        for (int i = 3; i <= n; i++) {
            a = b;
            b = c;
            c = a + b;
        }

        return c;
    }
};
