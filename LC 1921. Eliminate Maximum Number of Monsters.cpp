class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size(), ret = 0;
        vector<int> time(n,0);
        for(int i=0; i<n; i++){
            int tmp = dist[i]/speed[i];
            if(dist[i] % speed[i] == 0){
                tmp--;
            }
            time[i] = tmp;
        }
        sort(time.begin(), time.end());
        for(int i=0; i<n; i++){
            if(time[i] < i){
                return ret;
            }
            ret++;
        }
        return ret;
    }
};
