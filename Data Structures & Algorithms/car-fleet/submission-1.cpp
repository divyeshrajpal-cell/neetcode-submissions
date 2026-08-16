class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();

        vector<pair<int, double>> cars;

        // Store position and time needed to reach target
        for (int i = 0; i < n; i++) {
            double time = (double)(target - position[i]) / speed[i];
            cars.push_back({position[i], time});
        }

        // Sort cars by position from closest to target to farthest
        sort(cars.begin(), cars.end());

        stack<double> st;

        // Start from the car closest to target
        for (int i = n - 1; i >= 0; i--) {
            double time = cars[i].second;

            // This car cannot catch the fleet ahead
            if (st.empty() || time > st.top()) {
                st.push(time);
            }
            // Otherwise it catches the fleet ahead
        }

        return st.size();
    }
};
