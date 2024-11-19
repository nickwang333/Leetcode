class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ret = 0, total = 0, distinct = 0;
        int n = nums.size();
        unordered_map<int, int> m;
        for(int i=0; i<k; i++){
            total += nums[i];
            m[nums[i]]++;
            if(m[nums[i]] == 1){
                distinct++;
            }
            else if(m[nums[i]] == 2){
                distinct--;
            }
        }
        if(distinct == k){
            ret = total;
        } 
        for(int i=k; i<n; i++){
            m[nums[i-k]]--;
            if(m[nums[i-k]] == 0){
                distinct--;
            }
            else if(m[nums[i-k]] == 1){
                distinct++;
            }
            m[nums[i]]++;
            if(m[nums[i]] == 1){
                distinct++;
            }
            else if(m[nums[i]] == 2){
                distinct--;
            }
            total -= nums[i-k];
            total += nums[i];
            if(distinct == k){
                ret = max(ret, total);
            }
        }
        return ret;
    }
};
