class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i+=3){
            vector<int> tmp{nums[i], nums[i+1], nums[i+2]};
            ret.push_back(tmp);
            if(nums[i+2] - nums[i] > k){
                vector<vector<int>> nul;
                return nul;
            }
        }
        return ret;
    }
};
