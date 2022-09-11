class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int ret = 1, tmp = 0, tsum = 0, prev = 0;
        for(int i=0; i<nums.size(); i++){
            cout << tsum << " ";
            if( (tsum & nums[i]) == 0){
                tmp++;
                tsum |= nums[i];
                ret = max(ret,tmp);
            }
            else{
                while(prev <= i && (tsum & nums[i]) != 0){
                    int tmp = INT_MAX ^ nums[prev];
                    tsum &= tmp;
                    prev++;
                }
                tmp = i-prev+1;
                tsum |= nums[i];
                ret = max(ret,tmp);
            }
        }
        cout << tsum;
        ret = max(ret,tmp);
        return ret;
    }
};
