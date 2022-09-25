class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int index = 0, maxi = nums[0], ret = 1;;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] > maxi){
                maxi = nums[i];
                index = i;
            }
        }
        int tmp = 1;
        for(int i=1; i<nums.size(); i++){
            if(nums[i] == nums[i-1] && nums[i] == maxi){
                tmp++;
                ret = max(ret, tmp);
            }
            else{
                tmp = 1;
            }
        }
        ret = max(ret, tmp);
        return ret;
    }
};
