class Solution {
public:
    int firstUniqChar(string s) {
        int ret;
        vector<int> v(26,0);
        queue<int> q, q2;
        for(int i=0; i<s.size(); i++){
            v[s[i]-'a']++;
            if(v[s[i]-'a']==1){
                q.push(s[i]-'a');
                q2.push(i);
            }
        }
        while(!q.empty()){
            if(v[q.front()]==1){
                return q2.front();
            }
            else{
                q.pop();
                q2.pop();
            }
        }
        return -1;
    }
};
