class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 0;
        if (digits[digits.size() - 1] + 1 <= 9) {
            digits[digits.size() - 1]++;
            return digits;
        }
        else {
            carry = 1;
            digits[digits.size() - 1] = 0;
        }

        for (int i = digits.size() - 2; i >= 0; i--) {
            if (digits[i] + carry <= 9) {
                digits[i] += carry;
                return digits;
            }
            else digits[i] = 0;
        }

        digits.insert(digits.begin(), carry);
        return digits;
    }
};
