class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        queue<string> q; queue<int> reg; queue<int> reg2;
        for(int i=0; i<n*2; i++){
            if(i==0){
                string s = "(";
                q.push(s);
                reg.push(0);
                reg2.push(1);
            }
            else{
                int qs = q.size();
                for(int j=0; j<qs; j++){
                    string s = q.front();
                    int it = reg.front();
                    int it2 = reg2.front();
                    q.pop();
                    reg.pop();
                    reg2.pop();
                    if(it2 == n){
                        s+=')';
                        q.push(s);
                        reg.push(it+1);
                        reg2.push(it2);
                    }
                    else if(it>=it2){
                        s+='(';
                        q.push(s);
                        reg.push(it);
                        reg2.push(it2+1);
                    }
                    else{
                        string tmp = s;
                        tmp += '(';
                        q.push(tmp);
                        reg.push(it);
                        reg2.push(it2+1);
                        s += ')';
                        q.push(s);
                        reg.push(it+1);
                        reg2.push(it2);
                    }
                }
            }
        }
        while(!q.empty()){
            ret.push_back(q.front());
            q.pop();
        }
        return ret;
    }
};
