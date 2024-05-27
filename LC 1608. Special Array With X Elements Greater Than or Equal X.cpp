class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i=0; i<=n; i++){
            int count = 0;
            for(int j:nums){
                if(j >= i){
                    break;
                }
                count++;
            }
            if(n-count == i){
                return i;
            }
        }
        return -1;
    }
};
