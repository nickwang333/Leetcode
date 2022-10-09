class Solution {
public:
    int findMin(vector<int>& v){
        for(int i=0; i<26; i++){
            if(v[i] != 0){
                return i;
            }
        }
        return -1;
    }

    string robotWithString(string s) {
        stack<char> s2;
        string ret;
        int n = s.size();
        vector<int> v(26,0);
        for(int i=0; i<n; i++){
            v[s[i]-'a']++;
        }
        int mini = findMin(v);
        for(int i=0; i<n; i++){
            v[s[i]-'a']--;
            if((s[i]-'a') == mini){
                ret += s[i];
                if(v[s[i]-'a'] == 0){
                    mini = findMin(v);
                    while(!s2.empty() && (s2.top()-'a')<=mini){
                        ret += s2.top();
                        s2.pop();
                    }
                }
            }
            else{
                s2.push(s[i]);
            }
        }
        while(!s2.empty()){
            ret += s2.top();
            s2.pop();
        }
        return ret;
    }
};
