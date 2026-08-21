class TimeMap {
private:
    // key -> {timestamp, value}
    unordered_map<string, vector<pair<int, string>>> mp;

public:
    TimeMap() {
    }

    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) {
        if (mp.find(key) == mp.end())
            return "";

        vector<pair<int, string>>& values = mp[key];

        int left = 0;
        int right = values.size() - 1;

        string result = "";

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (values[mid].first <= timestamp) {
                // This timestamp is valid.
                result = values[mid].second;

                // Try to find a later valid timestamp.
                left = mid + 1;
            }
            else {
                // Timestamp is too large.
                right = mid - 1;
            }
        }

        return result;
    }
};