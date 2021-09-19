void back_track(vector<int>& nums, vector<vector<int>>& ret, int tmp){
    if(tmp==nums.size()){
        ret.push_back(nums);
    }
    for(int i=tmp; i<nums.size(); i++){
        swap(nums[tmp], nums[i]);
        back_track(nums, ret, tmp+1);
        swap(nums[tmp], nums[i]);
    }
    
}
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        int n = nums.size();
        back_track(nums, ret, 0);
        return ret;
    }
};
