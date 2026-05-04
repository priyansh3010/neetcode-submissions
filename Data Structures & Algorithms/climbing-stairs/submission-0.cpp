class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        long long int result;
        long long int num1 = 1;
        long long int num2 = 1;

        for (int i = 1; i < n - 1; i++) {
            long long int temp = num1;
            num1 += num2;
            num2 = temp;
        }

        return num1 + num2;
    }
};
