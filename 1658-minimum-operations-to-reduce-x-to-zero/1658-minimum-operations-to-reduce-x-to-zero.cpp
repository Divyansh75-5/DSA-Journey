class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
         int total = accumulate(nums.begin(), nums.end(), 0);
        int target = total - x;

        if (target < 0) return -1;

        int l = 0, sum = 0, mx = -1;

        for (int r = 0; r < nums.size(); r++) {
            sum += nums[r];

            while (sum > target)
                sum -= nums[l++];

            if (sum == target)
                mx = max(mx, r - l + 1);
        }

        return mx == -1 ? -1 : nums.size() - mx;
    }
};