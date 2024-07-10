class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long long tmp = 0, ret = -1;
        for(int i=0; i<nums.size()-1; i++){
            tmp += nums[i];
            if(tmp > nums[i+1] && i > 0){
                ret = max(ret, tmp + nums[i+1]);
            }
        }
        return ret;
    }
};
