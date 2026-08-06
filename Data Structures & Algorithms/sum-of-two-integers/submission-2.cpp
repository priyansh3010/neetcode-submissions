class Solution {
public:
    int getSum(int a, int b) {

        // 50 = 110010
        // 30 = 011110
        // 20 = 010100

        int res = 0;
        int carry = 0;

        for (int i = 0; i < 32; i++) {
            int a_bit = (a >> i) & 1;
            int b_bit = (b >> i) & 1;
            int cur_bit = a_bit ^ b_bit ^ carry;
            carry = ((a_bit && b_bit) || (b_bit && carry) || (a_bit && carry)) ? 1 : 0;
            if (cur_bit) {
                res |= (1 << i);
            }
        }

        if (res > 0x7FFFFFFF) res = ~(res ^ 0xFFFFFFFF);

        return res;
    }
};