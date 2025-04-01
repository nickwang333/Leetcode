class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int diff = nums[1] - nums[0];
        if((nums[1] <= nums[0]) ){
            diff = -1;
        }
        int mini = min(nums[0], nums[1]);
        for(int i=2; i<nums.size(); i++){
            if(nums[i] > mini){
                diff = max(diff, nums[i] - mini);
            }
            mini = min(mini, nums[i]);
        }
        return diff;
    }
};
