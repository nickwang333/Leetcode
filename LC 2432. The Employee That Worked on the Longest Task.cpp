class Solution {

public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        sort(logs.begin(), logs.end(), [](const vector<int> & a, const vector<int> & b) -> bool
        { 
            return a[1] < b[1]; 
        });
        int ret = logs[0][0], time = logs[0][1];
        for(int i = 1; i<logs.size(); i++){
            if(logs[i][1] - logs[i-1][1] > time){
                ret = logs[i][0];
                time = logs[i][1] - logs[i-1][1];
            }
            else if(logs[i][1] - logs[i-1][1] == time && logs[i][0] < ret){
                ret = logs[i][0];
            }
        }
        return ret;
    }
};
