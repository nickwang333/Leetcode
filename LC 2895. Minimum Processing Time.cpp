class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        int n = tasks.size(), m = processorTime.size(), ret = 0;
        sort(tasks.begin(), tasks.end());
        sort(processorTime.rbegin(), processorTime.rend());
        for(int i=0; i<m; i++){
            int tmp = processorTime[i] + tasks[i*4+3];
            ret = max(ret, tmp);
        }
        return ret;
    }
};
