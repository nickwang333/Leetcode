class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        vector<int> dp(value, 0);
        for(int i:nums){
            int tmp = (i%value+value)%value;
        
            dp[tmp] += 1;
        }
        for(int i=0; i<nums.size(); i++){
            dp[i%value]--;
            if(dp[i%value] == -1){
                return i;
            }
        }
        return nums.size();

    }
};
