class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        int ret = 0;
        for(int i=0; i<nums.size(); i++){
            sort(nums[i].begin(), nums[i].end());
        }
        for(int i=0; i<nums[0].size(); i++){
            int tmp = nums[0][i];
            for(int j=0; j<nums.size(); j++){
                tmp = max(tmp, nums[j][i]);
            }
            ret += tmp;
        }
        return ret;
    }
};
