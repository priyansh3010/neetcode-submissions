class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> visited;

        while (n != 1) {
            int temp = 0;
            while (n > 0) {
                int curr = n % 10;
                temp += (curr * curr);
                n /= 10;
            }
            n = temp;
            if (visited.find(n) != visited.end()) return false;
            visited.insert(n);
        }

        return true;
    }
};
