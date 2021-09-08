class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size(), high = values[0], ret = 0;
        for(int i=1; i<n; i++){
            int curr = values[i] + high - 1;
            ret = max(ret, curr);
            high = max(high-1, values[i]);
        }
        return ret;
    }
};
