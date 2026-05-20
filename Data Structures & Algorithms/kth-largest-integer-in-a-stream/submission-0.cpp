class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int k;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;

        for (int num : nums) {
            if (minHeap.size() == k) {
                if (minHeap.top() < num) minHeap.pop();
                else continue;
            } 
            minHeap.push(num);
        }
    }
    
    int add(int val) {
        if (minHeap.size() == k) {
            if (minHeap.top() < val) {
                minHeap.pop();
                minHeap.push(val);
            }
        } 
        else minHeap.push(val);

        return minHeap.top();
    }
};
