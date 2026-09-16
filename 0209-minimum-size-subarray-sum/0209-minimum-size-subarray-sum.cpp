class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum =0;
        int res = INT_MAX;
        int n = nums.size();
        int low = 0;
        int high =0;
        while(high< n){
            sum = sum+ nums[high];
            while(sum >= target){
                int len = high -low +1;
                res = min(res,len);
                sum = sum-nums[low];
                low++;
            }
            high ++;
        }
        return res == INT_MAX ? 0 : res;
    }
};