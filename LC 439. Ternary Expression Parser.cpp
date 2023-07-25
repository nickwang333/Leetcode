class Solution {
public:
    string parseTernary(string expression) {
        stack<char> s, schar;
        reverse(expression.begin(), expression.end());
        for(char i:expression){
            if(i == '?' || i == ':'){
                schar.push(i);
            }
            else{
                s.push(i);
                if(schar.size() >= 2){
                    if(schar.top() == '?'){
                        schar.pop();
                        if(schar.top() == ':'){
                            schar.pop();
                            char tmp1 = s.top();
                            s.pop();
                            char tmp2 = s.top();
                            s.pop();
                            char tmp3 = s.top();
                            s.pop();
                            if(tmp1 == 'T'){
                                s.push(tmp2);
                            }
                            else{
                                s.push(tmp3);
                            }
                        }
                        else{
                            schar.push('?');
                        }
                    }
                }
            }
        }
        char tmp = s.top();
        string ret;
        ret += tmp;
        return ret;
    }
};
