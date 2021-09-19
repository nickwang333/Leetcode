void back_track(vector<int>& nums, vector<vector<int>>& ret, int tmp){
    if(tmp==nums.size()){
        ret.push_back(nums);
    }
    for(int i=tmp; i<nums.size(); i++){
        swap(nums[i], nums[tmp]);
        back_track(nums,ret,tmp+1);
        swap(nums[i], nums[tmp]);
    }
}
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ret;
        back_track(nums,ret,0);
        map<vector<int>, int> m;
        for(auto i:ret){
            m[i]++;
        }
        vector<vector<int>> ret2;
        for(auto it=m.begin(); it!=m.end(); it++){
            ret2.push_back(it->first);
        }
        return ret2;
    }
};
