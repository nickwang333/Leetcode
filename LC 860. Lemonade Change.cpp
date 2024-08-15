class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int total = 0, five = 0, ten = 0;
        for(int i:bills){
            if(i == 5){
                five++;
            }
            else if(i == 10){
                if(five == 0){
                    return false;
                }
                five--;
                ten++;
            }
            else{
                if(ten > 0){
                    ten--;
                    if(five == 0){
                        return false;
                    }
                    five--;
                }
                else{
                    if(five < 3){
                        return false;
                    }
                    five -= 3;
                }
            }
        }
        return true;
    }
};
