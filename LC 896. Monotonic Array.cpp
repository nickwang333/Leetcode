class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        if(nums.size() <= 2){
            return true;
        }
        int n = nums.size(),ncounter = 0, pcounter = 0;
        for(int i=0; i<n-1; i++){
            int tmp = nums[i]-nums[i+1];
            if(tmp > 0){
                ncounter++;
            }
            else if(tmp < 0){
                pcounter++;
            }
        }
        return !(ncounter > 0 && pcounter > 0);
    }
};
