class Solution {
public:
    int countArrays(vector<int>& original, vector<vector<int>>& bounds) {
        int high = INT_MAX, low = INT_MIN, n = original.size();
        for(int i=0; i<n; i++){
            high = min(high, bounds[i][1] - original[i]);
            low = max(low, bounds[i][0] - original[i]);
        }
        return max(0, high-low+1);
    }
};
