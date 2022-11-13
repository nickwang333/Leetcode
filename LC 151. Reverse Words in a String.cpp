class Solution {
public:
    string reverseWords(string s) {
        string ret, tmp = "";
        stack<string> s2;
        for(char i:s){
            if(i == ' '){
                if(tmp != ""){
                    s2.push(tmp);
                }
                tmp = "";
            }
            else{
                tmp += i;
            }
        }
        s2.push(tmp);
        while(!s2.empty()){
            string tmp2 = s2.top();
            ret += s2.top();
            s2.pop();
            if(!s2.empty() && tmp2 != ""){
                ret += ' ';
            }
        }
        return ret;
    }
};
