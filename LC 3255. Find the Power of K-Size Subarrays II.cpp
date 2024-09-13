class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ret(n-k+1, -1);
        if(k == 1){
            ret = nums;
            return ret;
        }
        int tmp = 0;
        for(int i=1; i<n; i++){
            if(i < k){
                if(nums[i] - nums[i-1] == 1){
                    tmp++;
                }
                if(i == k-1){
                    if(tmp == k-1){
                        ret[i-k+1] = nums[i];
                    }
                }
            }
            else{
                if(nums[i] - nums[i-1] == 1){
                    tmp++;
                }
                if(nums[i-k+1] - nums[i-k] == 1){
                    tmp--;
                }
                if(tmp == k-1){
                    ret[i-k+1] = nums[i];
                }
            }
        }
        return ret;
    }
};
