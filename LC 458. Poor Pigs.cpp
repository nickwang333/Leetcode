class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int round = minutesToTest/minutesToDie, ret = 0, tmp = 1;
        while(tmp<buckets){
            tmp*=(round+1);
            ret++;
        }
        return ret;
    }
};
