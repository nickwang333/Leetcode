class Solution {
public:
    string simplifyPath(string path) {
        string ret, tmp;
        stack<string> s;
        for(int i=1; i<path.size(); i++){
            if(path[i] == '/'){
                if(tmp == ".."){
                    if(!s.empty()){
                        s.pop();
                    }
                }
                else if(tmp != "" && tmp != "."){
                    s.push(tmp);
                }
                tmp = "";
            }
            else{
                tmp += path[i];
            }
        }
        if(tmp == ".."){
            if(!s.empty()){
                s.pop();
            }
        }
        else if(tmp != "" && tmp != "."){
            s.push(tmp);
        }
        if(!s.empty()){
            ret = s.top();
            s.pop();
        }
        while(!s.empty()){
            ret = s.top()+ "/" + ret;
            s.pop();
        }
        ret = "/" + ret;
        return ret;
    }
};
