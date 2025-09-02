class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<vector<int>> v;
        for(int i=0; i<n; i++) {
            v.push_back(vector<int> {capital[i], profits[i]});
        }
        sort(v.begin(), v.end());
        int p0 = 0;
        priority_queue<int> q;
        for(int i=0; i<k; i++) {
            while(p0 < n && v[p0][0] <= w){
                q.push(v[p0][1]);
                p0++;
            }
            if(q.empty()){
                return w;
            }
            w += q.top();
            q.pop();
        }
        return w;
    }
};
