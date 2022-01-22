class Solution {
public:
    int calculate(string s) {
        int ret = 0;
        stack<int> s1;
        stack<string> s2;
        for(int i=0; i<s.size(); ++i){
            if(isdigit(s[i])){
                int number = s[i]-'0';
                while(isdigit(s[i+1]) || s[i+1]==' '){
                    if(isdigit(s[i+1])){
                        number = number*10 + (s[i+1]-'0');
                    }
                    i++;
                }
                if(s2.empty()){
                    s2.push("+");
                }
                if(!s1.empty() && (s2.top() == "*" || s2.top() =="/")){
                    if(s2.top() == "*"){
                        int tmp = s1.top();
                        s1.pop();
                        s1.push(tmp*(number));
                    }
                    else{
                        int tmp = s1.top();
                        s1.pop();
                        s1.push(tmp/(number));
                    }
                    s2.pop();
                }
                else{
                    s1.push(number);
                }
                
            }
            else if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'){
                string tmp = "";
                tmp += s[i];
                s2.push((tmp));
            }
        }
        while(!s1.empty()){
            
            if(s2.top()=="+"){
                s2.pop();
                ret += s1.top();
                s1.pop();
            }
            else{
                s2.pop();
                ret -= s1.top();
                s1.pop();
            }
        }
        return ret;
    }
};
