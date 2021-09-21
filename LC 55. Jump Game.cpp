class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(), tsum = nums[0];
        for(int i=0; i<n; i++){
            if(i<=tsum){
                tsum = max(tsum,nums[i]+i);
            }
        }
        return tsum>=n-1;
    }
};
