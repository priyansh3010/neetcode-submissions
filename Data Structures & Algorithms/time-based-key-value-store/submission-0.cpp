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
        vector<pair<int, string>> stores = storage[key];

        int left = 0;
        int right = stores.size() - 1;

        bool found = false;
        int mid;
        while (left <= right && !found) {
            mid = left + (right - left) / 2;

            if (stores[mid].first < timestamp) left = mid + 1;
            else if (stores[mid].first > timestamp) right = mid - 1;
            else found = true;
        }

        if (found) return stores[mid].second;

        left = 0; right = stores.size() - 1;

        found = false;
        while (left <= right && !found) {
            mid = left + (right - left) / 2;

            if (stores[mid].first < timestamp) {
                if (mid + 1 < stores.size() && stores[mid + 1].first < timestamp) left = mid + 1;
                else found = true;
            }
            else right = mid - 1;
        }

        if (found) return stores[mid].second;
        return "";
    }
};
