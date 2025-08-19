class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ret = 0, prev = 0;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(nums[i] == 0){
                prev++;
                ret += prev;
            }
            else{
                prev = 0;
            }
        }
        return ret;
    }
};
