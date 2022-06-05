class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        int ret = 0, first_negative = -1, num_nega = 0, prev_nega = -1, tmp_len = 0;
        for(int i=0; i<n; i++){
            if(nums[i] == 0){
                first_negative = -1;
                num_nega = 0;
                prev_nega = -1;
                tmp_len = 0;
            }
            else if(nums[i] < 0){
                if(first_negative == -1){
                    first_negative = i;
                    prev_nega = i;
                }
                tmp_len++;
                num_nega++;
                if(num_nega%2 == 0){
                    ret = max(ret, tmp_len);
                }
                else{
                    int tmp1 = i-first_negative;
                    int tmp2 = tmp_len-1;
                    ret = max(ret, max(tmp1, tmp2));
                
                }
                prev_nega = i;
            }
            else{
                tmp_len++;
                if(num_nega%2 == 0){
                    ret = max(ret, tmp_len);
                }
                else{
                    int tmp1 = i-first_negative;
                    int tmp2 = tmp_len-(i-prev_nega)-1;
                    ret = max(ret, max(tmp1, tmp2));
                }
            }
        }
        return ret;
    }
};
