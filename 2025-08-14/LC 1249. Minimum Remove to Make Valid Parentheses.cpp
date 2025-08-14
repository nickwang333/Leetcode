class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.size();
        stack<int> s1, s2;
        queue<int> q1;
        for(int i=0; i<n; i++){
            if(s[i] == '('){
                s1.push(i);
            }
            else if(s[i] == ')'){
                if(s1.empty()){
                    q1.push(i);
                }
                else{
                    s1.pop();
                }
            }
        }
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        string ret = "";
        for(int i=0; i<n; i++){
            if(!q1.empty() && q1.front() == i){
                q1.pop();
            }
            else if(!s2.empty() && s2.top() == i){
                s2.pop();
            }
            else{
                ret += s[i];
            }
        }
        return ret;
    }
};
