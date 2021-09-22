class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        if(n<3){
            return false;
        }
        int min1 = nums[0], min2 = nums[0];
        vector<int> v(n,1);
        for(int i=1; i<n; i++){
            if(nums[i]>min2){
                if(min1==min2){
                    min2 = nums[i];
                }
                else{
                    return true;
                }
            }
            if(nums[i]<min1){
                if(min1==min2){
                    min2 = nums[i];
                }
                min1 = nums[i];
            }
            else if(nums[i]<min2 && nums[i]!=min1){
                min2 = nums[i];
            }
        }
        return false;
    }
};
