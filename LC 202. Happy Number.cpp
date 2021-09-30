class Solution {
public:
    bool isHappy(int n) {
        map<int, int > m;
        while(n!=1){
            int tsum = 0;
            while(n>0){
                tsum += (n%10)*(n%10);
                n /= 10;
            }
            if(m[tsum] > 0){
                return false;
            }
            m[tsum]++;
            n = tsum;
        }
        return true;
    }
};
