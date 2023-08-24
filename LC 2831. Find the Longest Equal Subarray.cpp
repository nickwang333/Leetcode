class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        int n = nums.size(), ret = 0;
        unordered_map<int, vector<int>> m;
        for(int i=0; i<n; i++){
            m[nums[i]].push_back(i);
        }
        for(auto it:m){
            int sz = it.second.size(), j = 0;
            vector<int> tmpv = it.second;
            for(int i=0; i<sz; i++){
                while(j < sz && (tmpv[j] - tmpv[i] - 1 - (j-i-1)) <= k){
                    j++;
                }
                if(j<sz && (tmpv[j] - tmpv[i] - 1 - (j-i-1)) <= k){
                    ret = max(ret, j-i+1);
                }
                else{
                    ret = max(ret, j-i);
                }
            }
        }
        return ret;
    }
};
