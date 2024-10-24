class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> m;
        for(auto i:prerequisites){
            m[i[0]].push_back(i[1]);
        }
        queue<int> q;
        vector<int> visited(numCourses, 0);
        for(int i=0; i<numCourses; i++){
            if(m[i].size() == 0){
                q.push(i);
                visited[i] = 1;
            }
        }
        while(!q.empty()){
            int tmp = q.front();
            q.pop();
            for(int i=0; i<numCourses; i++){
                if(visited[i] == 0){
                    int flag = 0;
                    for(int j:m[i]){
                        if(visited[j] == 0){
                            flag = 1;
                            break;
                        }
                    }
                    if(flag == 0){
                        q.push(i);
                        visited[i] = 1;
                    }
                }
            }
        }
        for(int i:visited){
            if(i == 0){
                return false;
            }
        }
        return true;
    }
};
