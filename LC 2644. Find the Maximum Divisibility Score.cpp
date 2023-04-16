class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        int ret = 0, reti = INT_MAX;
        for(int i:divisors){
            int tmp = 0;
            for(int j:nums){
                if(j%i == 0){
                    tmp++;
                }
            }
            if(tmp > ret){
                ret = tmp;
                reti = i;
            }
            else if(tmp == ret && reti > i){
                reti = i;
            }
        }
        return reti;
    }
};
