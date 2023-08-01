class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ret;
        stack<int> s;
        queue<stack<int>> q;
        for(int i=1; i<=n-k+1; i++){
            stack<int> s;
            s.push(i);
            q.push(s);
        }
        while(!q.empty()){
            stack<int> tmp = q.front();
            q.pop();
            int sz = tmp.size();
            if(sz == k){
                vector<int> tmp2;
                while(!tmp.empty()){
                    tmp2.push_back(tmp.top());
                    tmp.pop();
                }
                ret.push_back(tmp2);
            }
            else{
                int end = n+sz-k+1;
                for(int i=tmp.top()+1; i<=end; i++){
                    stack<int> tmp3 = tmp;
                    tmp3.push(i);
                    q.push(tmp3);
                }
            }
        }
        return ret;
    }
};
