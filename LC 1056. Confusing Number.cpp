class Solution {
public:
    bool confusingNumber(int n) {
        int tmp = 0, tmp2 = n;
        while(n > 0){
            if(n % 10 == 2 || n % 10 == 3 || n % 10 == 4 || n % 10 == 5 || n % 10 == 7 ){
                return false;
            }
            else if(n % 10 == 6){
                tmp *= 10;
                tmp += 9;
            }
            else if(n%10 == 9){
                tmp *= 10;
                tmp += 6;
            }
            else{
                tmp *= 10;
                tmp += n%10;
            }
            n/=10;
        }
        return tmp != tmp2;
    }
};
