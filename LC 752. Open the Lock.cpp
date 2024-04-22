class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_map<string, int> visited, dead;
        for(string i:deadends){
            dead[i] = 1;
        }
        queue<string> q;
        q.push("0000");
        for(int i=0; i<10; i++){
            for(int j=0; j<10; j++){
                for(int k=0; k<10; k++){
                    for(int a=0; a<10; a++){
                        string tmp = to_string(i) + to_string(j) + to_string(k) + to_string(a);
                        visited[tmp] = -1;
                    }
                }
            }
        }
        if(dead["0000"] == 1){
            return -1;
        }
        visited["0000"] = 0;
        while(!q.empty()){
            string tmp = q.front();
            q.pop();
            vector<string> v = computeNear(tmp);
            for(string i:v){
                if(visited[i] == -1 && dead[i] != 1){
                    visited[i] = visited[tmp] + 1;
                    q.push(i);
                }
            }
        }
        return visited[target];
    }
    
    vector<string> computeNear(string tmp){
        vector<string> ret;
        for(int i=0; i<4; i++){
            string tmp2 = tmp;
            if(tmp[i] == '0'){
                tmp2[i] = '1';
                ret.push_back(tmp2);
                tmp2[i] = '9';
                ret.push_back(tmp2);
            }
            else if(tmp[i] == '9'){
                tmp2[i] = '0';
                ret.push_back(tmp2);
                tmp2[i] = '8';
                ret.push_back(tmp2);
            }
            else{
                tmp2[i] = tmp2[i]-1;
                ret.push_back(tmp2);
                tmp2[i] = tmp2[i]+2;
                ret.push_back(tmp2);
            }
        }
        return ret;
    }
};
