class Solution {
public:
    long long countPairs(vector<int>& nums1, vector<int>& nums2) {
        long long ret = 0;
        int n = nums1.size();
        vector<int> v(n);
        for(int i=0; i<n; i++){
            v[i] = nums1[i] - nums2[i];
        }
        sort(v.begin(), v.end());
        for(int i=0; i<n; i++){
            auto up= std::upper_bound (v.begin(), v.end(), -v[i]);
            if(up != v.end()){
                int val = up-v.begin();
                ret += min(n-val, n-i-1);
            }
        }
        return ret;
    }
};
