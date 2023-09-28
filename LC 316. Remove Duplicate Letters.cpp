class Solution {
public:
    string removeDuplicateLetters(string s) {
        map<char, int> m, m2, m3;
        stack<char> s2;
        string ret, ret2;
        for(char i:s){
            m[i]++;
        }
        for(char i:s){
            if(s2.empty()){
                s2.push(i);
                m[i]--;
                m2[i]++;
                if(m[i] == 0){
                    m.erase(i);
                }
            }
            else{
                auto it2 = m2.find(i);
                if(it2 == m2.end()){
                    while( !s2.empty() && s2.top() > i){
                        char tmp = s2.top();
                        auto it = m.find(tmp);
                        if(it == m.end() || it == m.begin()){
                            break;
                        }
                        else{
                            s2.pop();
                            m2.erase(tmp);
                        }
                    }
                    s2.push(i);
                    m2[i]++;
                }
                m[i]--;
                if(m[i] == 0){
                    m.erase(i);
                }
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
