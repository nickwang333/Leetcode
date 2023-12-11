class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ret(2,0);
        unordered_map<int, int> m1, m2;
        for(int i:nums1){
            m1[i]++;
        }
        for(int i:nums2){
            m2[i]++;
        }
        for(auto i:nums1){
            if(m2[i] >= 1){
                ret[0]++;
            }
        }
        for(auto i:nums2){
            if(m1[i] >= 1){
                ret[1]++;
            }
        }
        return ret;
    }
};
