class Solution {
public:
    int arraySign(vector<int>& nums) {
        int tmp = nums[0];
        for(int i=1; i<nums.size(); i++){
            tmp *= nums[i];
            if(tmp > 0){
                tmp = 1;
            }
            else if(tmp == 0){
                return 0;
            }
            else{
                tmp = -1;
            }
        }
        if(tmp > 0){
            return 1;
        }
        else if(tmp == 0){
            return 0;
        }
        else{
            return -1;
        }
    }
};
