class Solution {
public:
    string removeStars(string s) {
        string ret;
        stack<char> s1;
        for(char i:s){
            if(i == '*'){
                if(!s1.empty()){
                    s1.pop();
                }
            }
            else{
                s1.push(i);
            }
        }
        while(!s1.empty()){
            ret += s1.top();
            s1.pop();
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
