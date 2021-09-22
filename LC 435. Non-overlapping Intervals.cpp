class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int ret = 0;
        sort(intervals.begin(), intervals.end());
        int low = intervals[0][1];
        for(int i=1; i<intervals.size(); i++){
            if(intervals[i][0] >= low){
                low = intervals[i][1];
            }
            else{
                low = min(intervals[i][1], low);
                ret++;
            }
        }
        return ret;
    }
};
