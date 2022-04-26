class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ret = 0;
        for(int i:nums){
            if(100000<=i){
                ret++;
            }
            else if(i>= 1000 && i<10000){
                ret++;
            }
            else if(i >= 10 && i<100){
                ret++;
            }
        }
        return ret;
    }
};
