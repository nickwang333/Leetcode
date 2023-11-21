class Solution {
public:
    long long minimumSteps(string s) {
        long long ret = 0;
        int n = s.size(), fp = 0, sp = n-1;
        queue<int> q;
        for(int i=n-1; i>=0; i--){
            if(s[i] == '0'){
                q.push(i);
            }
            else{
                if(!q.empty()){
                    int tmp = q.front();
                    q.pop();
                    ret += (tmp-i);
                    q.push(i);
                }
            }
        }
        return ret;
    }
};
