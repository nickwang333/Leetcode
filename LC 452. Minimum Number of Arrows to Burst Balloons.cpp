class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(begin(points), end(points), [](const vector<int> &o1, const vector<int> &o2) {
            return (o1[1] < o2[1]);
        });
        int ret = 1, last = points[0][1];
        for(int i=1; i<points.size(); i++){
            if(points[i][0] > last){
                last = points[i][1];
                ret++;
            }
        }
        return ret;
    }
};
