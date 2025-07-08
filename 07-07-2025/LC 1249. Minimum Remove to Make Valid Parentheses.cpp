class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<char> s1;
        stack<int> s2;
        int n = s.size();
        for(int i=0; i<n; i++){
            if(s[i] == '('){
                s1.push('(');
                s2.push(i);
            }
            else if(s[i] == ')'){
                if(!s1.empty() && s1.top() == '('){
                    s1.pop();
                    s2.pop();
                }
                else{
                    s1.push(')');
                    s2.push(i);
                }
            }
        }
        stack<int> q;
        while(!s2.empty()){
            q.push(s2.top());
            s2.pop();
        }
        string ret;
        for(int i=0; i<n; i++){
            if(!q.empty() && i == q.top()){
                q.pop();
            }
            else{
                ret += s[i];
            }
        }
        return ret;
    }
};
