class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        vector<bool> visited(1001, false);
        int ret = 0;
        queue<int> q;
        q.push(start);
        while(!q.empty()){
            int sz = q.size();
            for(int i=0; i<sz; i++){
                int tmp = q.front();
                q.pop();
                if(tmp == goal){
                    return ret;
                }
                if(tmp>1000 || tmp<0 || visited[tmp]){
                    continue;
                }
                visited[tmp] = true;
                for(int j:nums){
                    int a = j^tmp, b = j+tmp, c = tmp-j;
                    q.push(a);
                    q.push(b);
                    q.push(c);
                }
            }
            ret++;
        }
        return -1;
    }
};
