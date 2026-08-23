class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        int sum =0;
         int n = nums.size();

        for(int i = 0; i < n; i++) {
            int left = 0;
            int right = n - 1;
            bool unique = true;

            while(left <= right) {
                if(left != i && nums[left] == nums[i])
                    unique = false;

                if(right != i && nums[right] == nums[i])
                    unique = false;

                left++;
                right--;
            }

            if(unique)
                sum += nums[i];
        }

        return sum;
    }
};