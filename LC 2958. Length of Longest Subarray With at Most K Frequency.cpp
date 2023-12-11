class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int p1 = 0, ret = 1, n = nums.size();
        for(int i=0; i<nums.size(); i++){
            m[nums[i]]++;
            while(m[nums[i]] > k){
                m[nums[p1]]--;
                p1++;
            }
            ret = max(ret, i-p1+1);
        }
        return ret;
    }
};
