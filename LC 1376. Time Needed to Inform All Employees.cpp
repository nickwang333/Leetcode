class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int ret = 0;
        queue<int> q, qtime;
        q.push(headID);
        qtime.push(0);
        unordered_map<int, vector<int>> sub;
        for(int i=0; i<n; i++){
            if(i!=headID){
                sub[manager[i]].push_back(i);
            }
        }
        while(!q.empty()){
            int sz = q.size();
            for(int i=0; i<sz; i++){
                int tmp1 = q.front(), tmp2 = qtime.front();
                ret = max(ret, tmp2);
                q.pop();
                qtime.pop();
                for(int j:sub[tmp1]){
                    q.push(j);
                    qtime.push(informTime[tmp1] + tmp2);
                }
            }
        }
        return ret;
    }
};
