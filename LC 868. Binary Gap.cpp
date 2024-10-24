class Solution {
public:
    int binaryGap(int n) {
        int ret = 0, prev = -1, counter = 0;
        while(n > 0){
            if(n % 2 == 1){
                if(prev != -1){
                    ret = max(ret, counter - prev);
                }
                prev = counter;
            }
            n /= 2;
            counter++;
        }
        return ret;
    }
};
