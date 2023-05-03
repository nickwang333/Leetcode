class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m1, m2;
        vector<vector<int>> ret(2);
        for(int i:nums1){
            m1[i] = 1;
        }
        for(int i:nums2){
            m2[i] = 1;
        }
        for(auto i:m1){
            if(m2[i.first] == 0){
                ret[0].push_back(i.first);
            }
        }
        for(auto i:m2){
            if(m1[i.first] == 0){
                ret[1].push_back(i.first);
            }
        }
        return ret;
    }
};
