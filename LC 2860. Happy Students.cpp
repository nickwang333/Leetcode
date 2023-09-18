class Solution {
public:
    int countWays(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ret = 0, n = nums.size();
        if(n == 1){
            if(nums[0] == 0){
                return 1;
            }
            else{
                return 0;
            }
        }
        for(int i=0; i<n-1; i++){
            if((i+1) > nums[i] && (nums[i+1] > (i+1))){
                ret++;
            }
        }
        if(nums[0] > 0){
            ret++;
        }
        if(nums[n-1] < n){
            ret++;
        }
        return ret;
    }
};
