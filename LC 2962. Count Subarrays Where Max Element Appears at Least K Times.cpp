class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long ret = 0;
        int maxi = nums[0], n = nums.size();
        vector<int> index;
        for(int i:nums){
            maxi = max(maxi, i);
        }
        for(int i=0; i<n; i++){
            if(nums[i] == maxi){
                index.push_back(i);
            }
        }
        int prev = -1;
        if(index.size() < k){
            return 0;
        }
        for(int i=0; i<index.size()-k+1; i++){
            int index1 = index[i];
            int index2 = index[i+k-1];
            ret += long(index1-prev)*long(n-index2);
            prev = index1;
        }
        return ret;
    }
};
