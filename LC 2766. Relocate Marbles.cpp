class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        int n = nums.size(), m = moveFrom.size();
        vector<int> ret;
        
        //use a hash map to store the origin's position
        unordered_map<int, int> m2;
        for(int i=0; i<n; i++){
            m2[nums[i]]++;
        }
        
        for(int i=0; i<m; i++){
            if(moveTo[i] != moveFrom[i]){
                m2[moveTo[i]] += m2[moveFrom[i]];
                m2[moveFrom[i]] = 0;
            }
        }
        for(auto i:m2){
            if(i.second != 0){
                ret.push_back(i.first);
            }
        }
        sort(ret.begin(), ret.end());
        return ret;
    }
};
