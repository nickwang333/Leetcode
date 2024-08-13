class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int total = 0, a = 0;
        for(int i:nums){
            total += i;
            if(i > 0 && i < 10){
                a += i;
            }
        }
        if(total % 2 == 0 && total/2 == a){
            return false;
        }
        return true;
    }
};
