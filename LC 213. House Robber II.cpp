class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1){return nums[0];}
        if(n==2){return max(nums[0], nums[1]);}
        if(n==3){return max(max(nums[0],nums[1]),nums[2]);}
        vector<int> v(n,0), rec(n,0);
        v[1] = nums[1]; v[2] = nums[2]; rec[0] = nums[0]; rec[1] = nums[1]; rec[2] = rec[0]+nums[2];
        int ret = max(max(v[1],v[2]), max(rec[1], rec[2]));
        for(int i=3; i<n; i++){
            v[i] = nums[i]+max(v[i-2], v[i-3]);
            ret = max(ret, v[i]);
        }
        for(int i=3; i<n-1; i++){
            rec[i] = nums[i]+max(rec[i-2], rec[i-3]);
            ret = max(ret, rec[i]);
        }
        return ret;
    }
};
