class Solution {
public:
    bool coincide(vector<int> b1, vector<int> b2){
        long long tmp = (pow(abs((b1[0]-b2[0])),2) + pow(abs(b1[1]-b2[1]),2));
        long long tmp2 = long(b1[2])*long(b1[2]);
        return tmp <= tmp2;
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<int> row(n,0);
        vector<vector<int>> adj(n,row);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(coincide(bombs[i], bombs[j])){
                    adj[i][j] = 1;
                }
                cout << adj[i][j] << " ";
            }
            cout << endl;
        }
        int ret = 0, tmp = 0;
        queue<int> q;
        for(int i=0; i<n; i++){
            vector<int> visited(n, 0);
            if(visited[i] == 0){
                q.push(i);
                visited[i] = 1;
                tmp = 0;
                while(!q.empty()){
                    int tmp1 = q.front();
                    q.pop();
                    tmp++;
                    cout << tmp1 << " ";
                    visited[tmp1] = 1;
                    for(int j=0; j<n; j++){
                        if(visited[j] == 0 && adj[tmp1][j] == 1){
                            q.push(j);
                            visited[j] = 1;
                        }
                    }
                }
                cout << endl;
                ret = max(tmp, ret);
            }
        }
        return ret;
    }
};
