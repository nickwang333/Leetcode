class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int prev = 0, n = nums.size(), ret = INT_MAX, total = 0;
        vector<int> digit(32, 0);
        for(int i=0; i<n; i++){
            total |= nums[i];
            int tmp = nums[i], counter = 0;
            if(nums[i] >= k){
                return 1;
            }
            while(tmp > 0){
                digit[counter] += (tmp % 2);
                tmp /= 2;
                counter++;
            }
            while(prev < i && total >= k){
                ret = min(ret, i-prev+1);
                int tmp2 = nums[prev];
                counter = 0;
                while(tmp2 > 0){
                    digit[counter] -= (tmp2 % 2);
                    if(tmp2 % 2 == 1 && digit[counter] == 0){
                        total -= (pow(2, counter));
                    }
                    tmp2 /= 2;
                    counter++;
                }
                prev++;
            }
        }
        if(ret == INT_MAX){
            return -1;
        }
        return ret;
    }
};
