class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size(), p0 = 0, curr = 0, ret = 0;
        while(p0 < n-1){
            int maxi = 0;
            for(int i=curr; i<=p0; i++){
                maxi = max(maxi, nums[i] + i);
            }
            p0 = maxi;
            ret++;
        }
        return ret;
    }
};
