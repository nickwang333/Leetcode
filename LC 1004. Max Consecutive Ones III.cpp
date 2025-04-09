class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size(), total = 0, begin = 0, ret = 0;
        for(int i=0; i<n; i++){
            if(nums[i] == 0){
                total++;
                while(total > k){
                    if(nums[begin] == 0){
                        total--;
                    }
                    begin++;
                }
            }
            ret = max(ret, i-begin+1);
        }
        return ret;
    }
};
