class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> s2;
        for(int i=0; i<s.size(); i++){
            if(s2.empty()){
                s2.push(s[i]);
            }
            else{
                if(s2.top() == s[i]){
                    s2.pop();
                }
                else{
                    s2.push(s[i]);
                }
            }
        }
        string ret;
        while(!s2.empty()){
            ret += s2.top();
            s2.pop();
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
