class Solution {
public:
    long long countSubarrays(vector<int>& nums) {
        int n = nums.size(), tmp = 1;
        long long ret = 1;
        vector<long long> v(n,1);
        for(int i=1; i<n; i++){
            if(nums[i] > nums[i-1]){
                v[i] += tmp;
                tmp++;
            }
            else{
                tmp = 1;
            }
            ret += v[i];
        }
        return ret;
    }
};
