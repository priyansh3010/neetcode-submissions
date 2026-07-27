class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;

        priority_queue<int, vector<int>, greater<int>> minHeap;
        unordered_map<int, int> freq;

        for (int card : hand) {
            if (freq.find(card) == freq.end()) minHeap.push(card);
            freq[card]++;
        }

        while (!minHeap.empty()) {
            int top = minHeap.top();
            for (int i = top; i < top + groupSize; i++) {
                if (freq.find(i) == freq.end()) {
                    cout << 1 << endl;
                    return false;
                } 
                freq[i]--;
                if (freq[i] == 0) {
                    if (i == minHeap.top()) minHeap.pop();
                    else return false;
                }
            }
        }

        return true;
    }
};
