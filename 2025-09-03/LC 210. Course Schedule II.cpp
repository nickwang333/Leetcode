class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> m;
        vector<int> deg(numCourses, 0);
        for(auto i:prerequisites){
            m[i[1]].push_back(i[0]);
            deg[i[0]]++;
        }
        queue<int> q;
        for(int i=0; i<numCourses; i++){
            if(deg[i] == 0){
                q.push(i);
            }
        }
        vector<int> ret;
        while(!q.empty()){
            int tmp = q.front();
            q.pop();
            ret.push_back(tmp);
            for(int i:m[tmp]){
                deg[i]--;
                if(deg[i] == 0){
                    q.push(i);
                }
            }
        }
        if(ret.size() == numCourses){
            return ret;
        }
        return vector<int> {};
    }
};
