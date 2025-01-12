class Solution {
public:
    bool canBeValid(string s, string locked) {
        int count = 0, n = s.size(), free = 0;
        stack<int> q;
        stack<int> q2;
        for(int i=0; i<n; i++){
            if(s[i] == '('){
                if(locked[i] == '0'){
                    q.push(i);
                }
                else{
                    q2.push(i);
                }
            }
            else{
                if(locked[i] == '0'){
                    q.push(i);
                }
                else{
                    if(!q2.empty()){
                        q2.pop();
                    }
                    else if(!q.empty()){
                        q.pop();
                    }
                    else{
                        return false;
                    }
                }
            }
        }
        if((q2.size() + q.size()) % 2 == 1){
            return false;
        }
        while(!q.empty() || !q2.empty()){
            if(q.empty()){
                return false;
            }
            if(q2.empty()){
                return true;
            }
            int tmp1 = q.top();
            q.pop();
            int tmp2 = q2.top();
            q2.pop();
            if(tmp2 > tmp1){
                return false;
            }
        }
        return true;
    }
};
