class Solution {
public:
    bool hasTrailingZeros(vector<int>& nums) {
        int num1 = -1, num2 = -1;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] % 2 == 0){
                if(num1 == -1){
                    num1 = 1;
                }
                else{
                    num2 = 1;
                }
            }
        }
        if(num1 == num2 && num1 == 1){
            return true;
        }
        return false;
    }
};
