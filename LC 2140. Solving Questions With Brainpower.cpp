class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        long long ret = questions[0][0];
        vector<long long> v(n, 0);
        for(int i=0; i<n; i++){
            int points = questions[i][0];
            int bp = questions[i][1];
            if(i > 0){
                v[i] = max(v[i], v[i-1]);
            }
            if(bp + i + 1 < n){
                v[i + bp + 1] = max(v[i + bp + 1], v[i] + points);
            }
            ret = max(ret, v[i] + questions[i][0]);
        }
        return ret;
    }
};
