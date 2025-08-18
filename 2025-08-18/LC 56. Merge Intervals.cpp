class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ret;
        sort(intervals.begin(), intervals.end());
        int end = intervals[0][1], start = intervals[0][0], n = intervals.size();
        for(int i=1; i<n; i++){
            if(intervals[i][0] <= end){
                end = max(end, intervals[i][1]);
            }
            else{
                ret.push_back(vector<int>{start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
        ret.push_back(vector<int>{start, end});
        return ret;
    }
};
