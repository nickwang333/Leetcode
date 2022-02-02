class Solution {
public:
    bool isPalindrome(int x) {
        long tmp = 0, tmp3 = x;
        if(x<0){
            return false;
        }
        while(x>0){
            int tmp2 = x%10;
            tmp = tmp*10+tmp2;
            x /= 10;
        }
        return tmp3 == tmp;
    }
};
