class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size(), fp = -1, sp = n, num0 = 0;
        vector<int> ret;
        for(int i=0; i<n; i++){
            if(nums[i] == 0){
                num0++;
            }
        }
        for(int i=0; i<num0; i++){
            ret.push_back(0);
        }
        for(int i=0; i<n; i++){
            if(nums[i] > 0){
                sp = i;
                break;
            }
        }
        for(int i=n-1; i>=0; i--){
            if(nums[i] < 0){
                fp = i;
                break;
            }
        }
        while(fp != -1 || sp != n){
            if(fp == -1){
                ret.push_back(nums[sp] * nums[sp]);
                sp++;
            }
            else if(sp == n){
                ret.push_back(nums[fp] * nums[fp]);
                fp--;
            }
            else{
                if(-nums[fp] > nums[sp]){
                    ret.push_back(nums[sp] * nums[sp]);
                    sp++;
                }
                else{
                    ret.push_back(nums[fp] * nums[fp]);
                    fp--;
                }
            }
        }
        
        return ret;
    }
};
