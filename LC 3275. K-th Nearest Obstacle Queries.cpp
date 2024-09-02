class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        int n = queries.size();
        priority_queue<int> pq;
        vector<int> ret(n, -1);
        for(int i=0; i<n; i++){
            int tmp = abs(queries[i][0]) + abs(queries[i][1]);
            if(pq.size() < k){
                pq.push(tmp);
                if(pq.size() == k){
                    ret[i] = pq.top();
                }
            }
            else{
                if(pq.top() > tmp){
                    pq.pop();
                    pq.push(tmp);
                }
                ret[i] = pq.top();
            }
        }
        return ret;
    }
};
