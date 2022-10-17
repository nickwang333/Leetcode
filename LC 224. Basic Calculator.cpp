class Solution {
    queue<string> parse(string s){
        queue<string> ret;
        int n = s.size(), operand = 0, operators = 0, flag = 0;
        for(int i=0; i<n; i++){
            if(s[i] == '+' || s[i] == '(' || s[i] == ')'){
                string tmp;
                tmp += s[i];
                ret.push(tmp);
                if(s[i] == '+'){
                    operators++;
                }
            }
            else if(s[i] == '-'){
                if(operators >= operand){
                    ret.push("0");
                    ret.push("-");
                }
                else{
                    string tmp;
                    tmp += s[i];
                    ret.push(tmp);
                    operators++;
                }
            }
            else if(s[i] != ' '){
                int j = i;
                string tmp = "";
                for(; j<n; j++){
                    if(s[j] == '+' || s[j] == '-' || s[j] == '(' || s[j] == ')'){
                        
                        break;
                    }
                    else if(s[j] != ' '){
                        tmp += s[j];
                    }
                }
                i = j-1;
                ret.push(tmp);
                operand++;
            }
        }
        return ret;
    }

    queue<string> toPostFix(queue<string> q){
        stack<string> s;
        queue<string> ret;
        while(!q.empty()){
            string tmp = q.front();
            q.pop();
            if(tmp == "+" || tmp == "-"){
                while(!s.empty() && s.top() != "("){
                    ret.push(s.top());
                    s.pop();
                }
                s.push(tmp);
            }
            else if(tmp == "(" || tmp == ")"){
                if(tmp == "("){
                    s.push(tmp);
                }
                else{
                    while(!s.empty() && s.top() != "("){
                        ret.push(s.top());
                        s.pop();
                    }
                    s.pop();
                      
                }
            }
            else{
                ret.push(tmp);
            }
        }
        while(!s.empty()){
            ret.push(s.top());
            s.pop();
        }
        return ret;
    }
public:
    int calculate(string s) {
        int ret = 0;
        queue<string> q, q2;
        q = parse(s);
        
        q2 = toPostFix(q);
        stack<int> s2;
        while(!q2.empty()){
            string tmp = q2.front();
            q2.pop();
            if(tmp == "+"){
                int tmp1 = s2.top();
                s2.pop();
                int tmp2 = s2.top();
                s2.pop();
                s2.push(tmp1+tmp2);
            } 
            else if(tmp == "-"){
                int tmp1 = s2.top();
                s2.pop();
                int tmp2 = s2.top();
                s2.pop();
                s2.push(tmp2-tmp1);
            }
            else{
                s2.push(stoi(tmp));
            }
        }
        return s2.top();
    }
};
