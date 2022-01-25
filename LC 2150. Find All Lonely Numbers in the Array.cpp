class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        vector<int> ret;
        unordered_map<int, int> m, m2;
        for(int i:nums){
            m[i]++;
            m2[i]++;
        }
        for(auto it=m.begin(); it!=m.end(); it++){
            if(it->second<2 && m2[it->first+1]==0 && m2[it->first-1]==0){
                ret.push_back(it->first);
            }
        }
        return ret;
    }
};
