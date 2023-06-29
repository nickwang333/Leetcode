class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        long long ret = 0;
        int n = nums.size(), fi = -1, si = -1, tmp = 0;
        for(int i=0; i<n; i++){
            if(nums[i] == 1){
                if(fi == -1){
                    fi = i;
                    tmp = 1;
                    ret = 1;
                }
                else if(si == -1){
                    si = i;
                    ret *= tmp;
                    ret %= 1000000007;
                    tmp = 1;
                }
                else{
                    ret *= tmp;
                    ret %= 1000000007;
                    tmp = 1;
                }
            }
            else{
                tmp++;
            }
        }
        return ret;
    }
};
