class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        unordered_map<int, vector<int>> pre, next;
        int ret = 0;
        vector<int> dp(n+1, -1), degree(n+1,0);
        for(auto i:relations){
            pre[i[1]].push_back(i[0]);
            next[i[0]].push_back(i[1]);
            degree[i[1]]++;
        }
        queue<int> q;
        for(int i=1; i<=n; i++){
            if(pre[i].size() == 0){
                q.push(i);
                dp[i] = time[i-1];
            }
        }
        while(!q.empty()){
            int tmp = q.front();
            q.pop();
            for(int i:next[tmp]){
                dp[i] = max(dp[i], dp[tmp] + time[i-1]);
                degree[i]--;
                if(degree[i] == 0){
                    q.push(i);
                }
            }
        }
        for(int i:dp){
            ret = max(ret, i);
        }
        return ret;
    }
};
