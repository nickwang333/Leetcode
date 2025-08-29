class Solution {
public:
    bool checkValidString(string s) {
        stack<int> s2, pos;
        int n = s.size();
        for(int i=0; i<n; i++){
            if(s[i] == '('){
                s2.push(i);
            }
            else if(s[i] == ')'){
                if(s2.empty() && pos.empty()){
                    return false;
                }
                else if(s2.empty()){
                    pos.pop();
                }
                else{
                    s2.pop();
                }
            }
            else{
                pos.push(i);
            }
        }
        while(!s2.empty() && !pos.empty()){
            if(s2.top() > pos.top()){
                return false;
            }
            s2.pop();
            pos.pop();
        }
        return s2.empty();
    }
};
