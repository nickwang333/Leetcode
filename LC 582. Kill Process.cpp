class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        map<int, vector<int>> m;
        for(int i=0; i<pid.size(); i++){
            m[ppid[i]].push_back(pid[i]);
        }
        vector<int> ret;
        ret.push_back(kill);
        queue<int> q;
        for(int i=0; i<m[kill].size(); i++){
            q.push(m[kill][i]);
        }
        while(!q.empty()){
            int tmp = q.front();
            q.pop();
            ret.push_back(tmp);
            for(int i=0; i<m[tmp].size(); i++){
                q.push(m[tmp][i]);
            }
        }
        return ret;
    }
};
