class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int ret = -1, index = -1;
        for(int i=0; i<points.size(); i++){
            if(points[i][0] == x || points[i][1] == y){
                if(ret == -1){
                    ret = max(abs(points[i][0]-x), abs(points[i][1]-y));
                    index = i;
                }
                else{
                    int tmp = max(abs(points[i][0]-x), abs(points[i][1]-y));
                    if(ret > tmp){
                        ret = tmp;
                        index = i;
                    }
                }
            }
        }
        return index;
    }
};
