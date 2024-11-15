class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ret = nums;
        int n = nums.size();
        // 11 = 1011    1001   1010
        for(int i=0; i<n; i++){
            if(nums[i] == 2){
                ret[i] = -1;
            }
            else{
                ret[i] = nums[i]-1;
                int total = 0, ones = 0, flag = 0;
                string tmp;
                while(nums[i] > 0){
                    if(flag == 0 && nums[i] % 2 == 1){
                        ones++;
                    }
                    else{
                        flag = 1;
                    }
                    nums[i] /= 2;
                    total++;
                }
                ret[i] = ret[i] - pow(2, ones-1)+1;
            }
        }
        return ret;
    }
};
