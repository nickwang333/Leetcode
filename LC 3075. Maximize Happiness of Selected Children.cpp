class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long ret = 0;
        sort(happiness.rbegin(), happiness.rend());
        for(int i=0; i<k; i++){
            int tmp1 = happiness[i] - i;
            int tmp = max(tmp1, 0);
            ret += tmp;
        }
        return ret;
    }
};
