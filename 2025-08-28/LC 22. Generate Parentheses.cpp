class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        queue<string> q1;
        // q2 for recording how many ( than ), q3 for recording (
        queue<int> q2, q3;
        q1.push("");
        q2.push(0);
        q3.push(0);
        for(int i=0; i<n*2; i++){
            int sz = q1.size();
            for(int j=0; j<sz; j++){
                string tmp1 = q1.front();
                q1.pop();
                int tmp2 = q2.front();
                q2.pop();
                int tmp3 = q3.front();
                q3.pop();
                if(tmp2 == 0){
                    q1.push(tmp1 + "(");
                    q2.push(tmp2+1);
                    q3.push(tmp3+1);
                }
                else if(tmp3 == n){
                    q1.push(tmp1 + ")");
                    q2.push(tmp2-1);
                    q3.push(tmp3);
                }
                else{
                    q1.push(tmp1 + "(");
                    q2.push(tmp2+1);
                    q3.push(tmp3+1);
                    q1.push(tmp1 + ")");
                    q2.push(tmp2-1);
                    q3.push(tmp3);
                }
            }
        }
        while(!q1.empty()){
            ret.push_back(q1.front());
            q1.pop();
        }
        return ret;
    }
};
