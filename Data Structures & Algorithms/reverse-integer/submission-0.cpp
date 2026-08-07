class Solution {
public:
    int reverse(int x) {
        if (x == INT_MIN) return 0;
        bool negative = x < 0 ? true : false;

        x = abs(x);
        int res = 0;

        while (x > 0) {
            if (res > INT_MAX / 10) return 0;
            res *= 10;
            int toAdd = x % 10;
            if (res > INT_MAX - toAdd) return 0;
            res += toAdd;
            x /= 10;
        }

        return negative ? res * -1 : res;
    }
};