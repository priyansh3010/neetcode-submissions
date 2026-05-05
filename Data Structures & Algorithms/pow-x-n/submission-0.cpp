class Solution {
public:
    double myPow(double x, int n) {
        if (x == 0) return 0;
        if (n == 0) return 1;

        double res = 1;
        int power = abs(n);

        while (power > 0) {
            if (power % 2 == 1) res *= x;
            x *= x;
            power >>= 1;
        }

        if (n < 0) return 1.0 / res;
        else return res;
    }
};
