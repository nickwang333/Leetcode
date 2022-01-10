class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        map<int, int> m1, m2;
        int ret = 0;
        int n = nums1.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                m1[nums1[i]+nums2[j]]++;
                m2[nums3[i]+nums4[j]]++;
            }
        }
        for(auto it=m1.begin(); it!=m1.end(); it++){
            ret += (it->second* m2[-it->first]);
        }
        return ret;
    }
};
