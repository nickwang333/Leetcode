class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(), ret = 0;
        vector<int> v(n,-1);
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                if(isConnected[i][j] == 1 && v[j]==-1){
                    queue<int> q;
                    v[i] = ret;
                    v[j] = ret;
                    q.push(j);
                    while(!q.empty()){
                        int tmp = q.front();
                        q.pop();
                        v[tmp] = ret;
                        for(int k=0; k<n; k++){
                            if(isConnected[tmp][k] == 1 && v[k]==-1){
                                q.push(k);
                            }
                        }
                    }
                    ret++;
                }
            }
        }
        
        
        return ret;
    }
};
