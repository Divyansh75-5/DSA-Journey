class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
     int left = 0;
     int right = 1;
     int unique = 1;
     int n = nums.size(); 
    while(right < n ){
        if(nums[right] == nums[right-1]){
            right++;
            continue;
        }
        nums[left +1]= nums[right];
            left++;
            unique++;
            right++;
    }
    return unique;
    }
};