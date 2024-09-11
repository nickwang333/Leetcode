class Solution {
public:
    int minBitFlips(int start, int goal) {
        int a = start ^ goal, ret = 0;
        while(a > 0){
            ret += (a%2);
            a /= 2;
        }
        return ret;
    }
};
