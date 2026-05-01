class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = *max_element(piles.begin(), piles.end());

        int minEat = INT_MAX;
        while (left <= right) {
            int toEat = left + (right - left) / 2;

            long long int hours = 0;
            for (int i = 0; i < piles.size(); i++) {
                if (piles[i] % toEat == 0) hours += (piles[i] / toEat);
                else hours += (piles[i] / toEat) + 1;
            }

            if (hours > h) left = toEat + 1;
            else {
                minEat = toEat;
                right = toEat - 1;
            }
        }

        return minEat;
    }
};
