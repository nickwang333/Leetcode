class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        unordered_map<int, int> m;
        vector<int> ret;
        int n = nums.size();
        for(auto i:nums){
            for(int j:i){
                m[j]++;
            }
        }
        for(auto i:m){
            if(i.second == n){
                ret.push_back(i.first);
            }
        }
        sort(ret.begin(), ret.end());
        return ret;
    }
};
