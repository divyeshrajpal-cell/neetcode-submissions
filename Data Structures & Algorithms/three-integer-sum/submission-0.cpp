class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;

        // Step 1: Sort the array
        sort(nums.begin(), nums.end());

        int n = nums.size();

        // Step 2: Fix one element
        for (int i = 0; i < n - 2; i++) {

            // Skip duplicate first elements
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int left = i + 1;
            int right = n - 1;

            // Step 3: Two-pointer search
            while (left < right) {

                int sum = nums[i] + nums[left] + nums[right];

                if (sum == 0) {
                    ans.push_back({nums[i], nums[left], nums[right]});

                    left++;
                    right--;

                    // Skip duplicate values for left pointer
                    while (left < right && nums[left] == nums[left - 1])
                        left++;

                    // Skip duplicate values for right pointer
                    while (left < right && nums[right] == nums[right + 1])
                        right--;

                } 
                else if (sum < 0) {
                    left++;      // Need a larger sum
                } 
                else {
                    right--;     // Need a smaller sum
                }
            }
        }

        return ans;
    }
};