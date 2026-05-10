class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> cars(position.size());

        for (int i = 0; i < position.size(); i++) {
            pair<int, int> temp;
            temp.first = position[i];
            temp.second = speed[i];

            cars[i] = temp;
        }

        sort(cars.begin(), cars.end(), [](pair<int, int> a, pair<int, int> b) {
            return a.first < b.first; 
        });

        stack<double> s;
        for (auto car : cars) {
            double timeTaken = (double)(target - car.first) / (double)car.second;

            while (!s.empty() && s.top() <= timeTaken) s.pop();
            s.push(timeTaken);
        }

        return s.size();
    }
};
