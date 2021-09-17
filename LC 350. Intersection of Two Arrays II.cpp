class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> m1, m2;
        for(int i:nums1){
            m1[i]++;
        }
        for(int i:nums2){
            m2[i]++;
        }
        vector<int> ret;
        for(auto it = m1.begin(); it!=m1.end(); it++){
            for(int i= 0; i<min(it->second, m2[it->first]); i++){
                ret.push_back(it->first);
            }
        }
        return ret;
    }
};
