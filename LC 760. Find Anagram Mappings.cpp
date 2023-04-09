class Solution {
public:
    vector<int> anagramMappings(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m2;
        for(int i=0; i<nums1.size(); i++){
            m2[nums2[i]] = i;
        }
        vector<int> ret(nums1.size());
        for(int i=0; i<nums1.size(); i++){
            ret[i] = m2[nums1[i]];
        }
        return ret;
    }
};
