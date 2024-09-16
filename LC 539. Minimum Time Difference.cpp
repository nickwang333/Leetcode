class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        sort(timePoints.begin(), timePoints.end());
        int ret = INT_MAX;
        for(int i=1; i<timePoints.size(); i++){
            int tmp1 = (timePoints[i][0] - '0') * 10;
            tmp1 +=  (timePoints[i][1] - '0');
            tmp1 *= 60;
            tmp1 += (timePoints[i][3] - '0') * 10;
            tmp1 +=  (timePoints[i][4] - '0');
            int tmp2 = (timePoints[(i-1)][0] - '0') * 10;
            tmp2 +=  (timePoints[i-1][1] - '0');
            tmp2 *= 60;
            tmp2 += (timePoints[i-1][3] - '0') * 10;
            tmp2 +=  (timePoints[i-1][4] - '0');

            ret = min(ret, abs(tmp1 - tmp2));
        }
        int n = timePoints.size();
        int tmp1 = (timePoints[0][0] - '0') * 10;
        tmp1 +=  (timePoints[0][1] - '0');
        tmp1 *= 60;
        tmp1 += (timePoints[0][3] - '0') * 10;
        tmp1 +=  (timePoints[0][4] - '0');
        int tmp2 = (timePoints[(n-1)][0] - '0') * 10;
        tmp2 +=  (timePoints[n-1][1] - '0');
        tmp2 *= 60;
        tmp2 += (timePoints[n-1][3] - '0') * 10;
        tmp2 +=  (timePoints[n-1][4] - '0');
        tmp2 = 24*60-tmp2;
        ret = min(ret, tmp1 + tmp2);
        return ret;
    }
};
