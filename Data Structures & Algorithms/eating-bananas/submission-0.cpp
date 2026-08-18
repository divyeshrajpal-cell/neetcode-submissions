class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());

        while (left < right) {
            int k = left + (right - left) / 2;

            long long hours = 0;

            for (int pile : piles) {
                hours += (pile + k - 1) / k;
            }

            if (hours <= h) {
                // k is fast enough, try a smaller speed
                right = k;
            } else {
                // k is too slow
                left = k + 1;
            }
        }

        return left;
    }
};