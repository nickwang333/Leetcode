class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        long long ret = 0, tmp = 0;;
        for(int i=0; i<n; i++){
            if(nums[i] == 0){
                tmp++;
                ret+=tmp;
            }
            else{
                tmp = 0;
            }
        }
        
        return ret;
    }
};
