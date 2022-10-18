class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int m = rooms.size(), n = rooms[0].size();
        queue<vector<int>> q;
        vector<int> row(n,-1);
        vector<vector<int>> v(m, row);
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(rooms[i][j] == 0){
                    v[i][j] = 0;
                    vector<int> tmp{i,j};
                    q.push(tmp);
                }
                else if(rooms[i][j] == -1){
                    v[i][j] = -2;
                }
            }
        }
        queue<vector<int>> tmp;
        
        while(!q.empty()){
            vector<int> point = q.front();
            q.pop();
            tmp.push(point);
            while(!tmp.empty()){
                vector<int> tmp2 = tmp.front();
                tmp.pop();
                if(tmp2[0]>0){
                    if(v[tmp2[0]-1][tmp2[1]] == -1){
                        v[tmp2[0]-1][tmp2[1]] = v[tmp2[0]][tmp2[1]]+1;
                        vector<int> tmp3{tmp2[0]-1, tmp2[1]};
                        tmp.push(tmp3);
                    }
                    else if(v[tmp2[0]-1][tmp2[1]] > v[tmp2[0]][tmp2[1]]+1){
                        v[tmp2[0]-1][tmp2[1]] = v[tmp2[0]][tmp2[1]]+1;
                        vector<int> tmp3{tmp2[0]-1, tmp2[1]};
                        tmp.push(tmp3);
                    }
                }
                if(tmp2[1]>0){
                    if(v[tmp2[0]][tmp2[1]-1] == -1){
                        v[tmp2[0]][tmp2[1]-1] = v[tmp2[0]][tmp2[1]]+1;
                        vector<int> tmp3{tmp2[0], tmp2[1]-1};
                        tmp.push(tmp3);
                    }
                    else if(v[tmp2[0]][tmp2[1]-1] > v[tmp2[0]][tmp2[1]]+1){
                        v[tmp2[0]][tmp2[1]-1] = v[tmp2[0]][tmp2[1]]+1;
                        vector<int> tmp3{tmp2[0], tmp2[1]-1};
                        tmp.push(tmp3);
                    }
                }
                if(tmp2[1]<n-1){
                    if(v[tmp2[0]][tmp2[1]+1] == -1){
                        v[tmp2[0]][tmp2[1]+1] = v[tmp2[0]][tmp2[1]]+1;
                        vector<int> tmp3{tmp2[0], tmp2[1]+1};
                        tmp.push(tmp3);
                    }
                    else if(v[tmp2[0]][tmp2[1]+1] > v[tmp2[0]][tmp2[1]]+1){
                        v[tmp2[0]][tmp2[1]+1] = v[tmp2[0]][tmp2[1]]+1;
                        vector<int> tmp3{tmp2[0], tmp2[1]+1};
                        tmp.push(tmp3);
                    }
                }
                if(tmp2[0]<m-1){
                    if(v[tmp2[0]+1][tmp2[1]] == -1){
                        v[tmp2[0]+1][tmp2[1]] = v[tmp2[0]][tmp2[1]]+1;
                        vector<int> tmp3{tmp2[0]+1, tmp2[1]};
                        tmp.push(tmp3);
                    }
                    else if(v[tmp2[0]+1][tmp2[1]] > v[tmp2[0]][tmp2[1]]+1){
                        v[tmp2[0]+1][tmp2[1]] = v[tmp2[0]][tmp2[1]]+1;
                        vector<int> tmp3{tmp2[0]+1, tmp2[1]};
                        tmp.push(tmp3);
                    }
                }
            }
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(v[i][j] == -2){
                    v[i][j] = -1;
                }
                else if(v[i][j] == -1){
                    v[i][j] = 2147483647;
                }
            }
        }
    
        rooms = v;
    }
};
