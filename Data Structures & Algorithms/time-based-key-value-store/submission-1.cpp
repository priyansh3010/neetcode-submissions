class TimeMap {
    unordered_map<string, vector<pair<int, string>>> storage;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        pair<int, string> temp = {timestamp, value};
        
        if (storage.find(key) == storage.end()) storage[key] = {temp};
        else storage[key].push_back(temp);
    }
    
    string get(string key, int timestamp) {
        auto& stores = storage[key];

        int left = 0, right = stores.size() - 1;
        int result = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (stores[mid].first <= timestamp) {
                result = mid;      
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return result == -1 ? "" : stores[result].second;
    }
};
