class MedianFinder {
public:
    priority_queue<int> firstHalf;
    priority_queue<int, vector<int>, greater<int>> secondHalf;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        
        if (firstHalf.size() == secondHalf.size()) {
            if (firstHalf.size() == 0 || num <= firstHalf.top()) firstHalf.push(num);
            else secondHalf.push(num);
        }
        else if (firstHalf.size() > secondHalf.size()) {
            if (num > firstHalf.top()) secondHalf.push(num);
            else {
                secondHalf.push(firstHalf.top());
                firstHalf.pop();
                firstHalf.push(num);
            }
        }
        else {
            if (num < secondHalf.top()) firstHalf.push(num);
            else {
                firstHalf.push(secondHalf.top());
                secondHalf.pop();
                secondHalf.push(num);
            }
        }
    }
    
    double findMedian() {
        bool isEven = !((firstHalf.size() + secondHalf.size()) % 2);

        if (isEven) return (double)(firstHalf.top() + secondHalf.top()) / 2.0;
        else return firstHalf.size() > secondHalf.size() ? firstHalf.top() / 1.0 : secondHalf.top() / 1.0;
    }
};
