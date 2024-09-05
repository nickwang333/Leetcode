class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int total = (m+n) * mean;
        for(int i:rolls){
            total -= i;
        }
        vector<int> ret(n), ret2;
        if(total < n || total > n*6){
            return ret2;
        }
        for(int i=0; i<n; i++){
            int val = min(6, total-(n-i-1));
            ret[i] = val;
            total -= val;
        }
        return ret;
    }
};
