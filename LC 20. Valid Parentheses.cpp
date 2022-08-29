class Solution {
public:
    bool isValid(string s) {
        stack<char> sc;
        for(char i:s){
            if(i == '{' || i == '[' || i == '('){
                sc.push(i);
            }
            else{
                if(i == '}'){
                    if(!sc.empty() && sc.top() == '{'){
                        sc.pop();
                    }
                    else{
                        return false;
                    }
                }
                if(i == ')'){
                    if(!sc.empty() && sc.top() == '('){
                        sc.pop();
                    }
                    else{
                        return false;
                    }
                }
                if(i == ']'){
                    if(!sc.empty() && sc.top() == '['){
                        sc.pop();
                    }
                    else{
                        return false;
                    }
                }
            }
        }
        return sc.empty();
    }
};
