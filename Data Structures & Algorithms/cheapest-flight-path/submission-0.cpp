class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> prices(n, INT_MAX);
        prices[src] = 0;

        for (int i = 0; i <= k; i++) {
            vector<int> temp = prices;

            for (const auto& flight : flights) {
                int s = flight[0];
                int d = flight[1];
                int c = flight[2];

                if (prices[s] == INT_MAX) continue;

                if (prices[s] + c < temp[d]) temp[d] = prices[s] + c;
            }

            prices = temp;
        }

        return prices[dst] == INT_MAX ? -1 : prices[dst];
    }
};
