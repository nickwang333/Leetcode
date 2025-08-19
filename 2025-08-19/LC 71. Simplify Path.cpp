class Solution {
public:
    string simplifyPath(string path) {
        stack<string> q;
        string ret = "", curr = "";
        int n = path.size();
        for(int i=0; i<n; i++){
            if(path[i] == '/'){
                if(curr != ""){
                    if(curr == ".."){
                        curr = "";
                        if(!q.empty()){
                            q.pop();
                        }
                    }
                    else if(curr == "."){
                        curr = "";
                        continue;
                    }
                    else{
                        q.push(curr);
                        curr = "";
                    }
                }
            }
            else{
                curr += path[i];
            }
        }
        if(curr != ""){
            if(curr == ".."){
                curr = "";
                if(!q.empty()){
                    q.pop();
                }
            }
            else if(curr == "."){
                curr = "";
            }
            else{
                q.push(curr);
                curr = "";
            }
        }
        stack<string> q2;
        while(!q.empty()){
            q2.push(q.top());
            q.pop();
        }
        while(!q2.empty()){
            ret += '/';
            ret += q2.top();
            q2.pop();
        }
        if(ret == ""){
            return "/";
        }
        return ret;
    }
};
