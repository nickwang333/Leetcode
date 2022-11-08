class Solution {
public:
    string makeGood(string s) {
        string ret;
        stack<char> s2;
        for(int i=0; i<s.size(); i++){
            if(s2.empty()){
                s2.push(s[i]);
            }
            else if((s2.top()-'A' == s[i]-'a') || (s2.top()-'a' == s[i]-'A')){
                s2.pop();
            }
            else{
                s2.push(s[i]);
            }
        }
        while(!s2.empty()){
            ret += s2.top();
            s2.pop();
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
