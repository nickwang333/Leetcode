class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> m;
        unordered_map<int, int> ind;
        for(auto i:prerequisites){
            m[i[1]].push_back(i[0]);
            ind[i[0]]++;
        }
        queue<int> q;
        for(int i=0; i<numCourses; i++){
            if(ind[i] == 0){
                q.push(i);
            }
        }
        int count = 0;
        
        while(!q.empty()){
            int tmp = q.front();
            q.pop();
            count++;
            for(int i:m[tmp]){
                ind[i]--;
                if(ind[i] == 0){
                    q.push(i);
                }
            }
        }
        return count == numCourses;
    }
};
