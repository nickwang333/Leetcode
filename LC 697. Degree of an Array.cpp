class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int maxi = 0, n = nums.size(), ret = INT_MAX;
        unordered_map<int, int> m;
        unordered_map<int, vector<int>> pos;
        for(int i=0; i<n; i++){
            m[nums[i]]++;
            pos[nums[i]].push_back(i);
            maxi = max(maxi, m[nums[i]]);
        }
        vector<int> element;
        for(auto it:m){
            if(it.second == maxi){
                element.push_back(it.first);
            }
        }
        for(auto it:m){
            if(it.second == maxi){
                int sz = pos[it.first].size();
                ret = min(ret, pos[it.first][sz-1] - pos[it.first][0] + 1);
            }
        }
        return ret;
    }
};
