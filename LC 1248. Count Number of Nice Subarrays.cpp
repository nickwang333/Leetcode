class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int total = 0, n = nums.size(), ret = 0, tmp = 0;
        unordered_map<int, int> m;
        m[0] = -1;
        for(int i=0; i<n; i++){
            if(nums[i] % 2 == 1){
                total++;
                m[total] = i;
            }
            if(total >= k){
                tmp = m[total-k+1] - m[total-k];
            }
            ret += tmp;
        }
        return ret;
    }
};
