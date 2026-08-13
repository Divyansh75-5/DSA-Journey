class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            a[i] = nums[i] * nums[i];
        }
        sort(a.begin(), a.end());
        return a;
    }
};
