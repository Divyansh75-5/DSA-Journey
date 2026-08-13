class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
   sort(nums.begin(), nums.end());

        int n = nums.size();
        int diff = INT_MAX;
        int res_sum = 0;

        for (int i = 0; i < n - 2; i++) {
            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int total = nums[i] + nums[left] + nums[right];
                int d = abs(target - total);

                if (diff > d) {
                    diff = d;
                    res_sum = total;
                }

                if (total == target) {
                    return res_sum;
                }

                if (total < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }    
        return res_sum;
    }
};