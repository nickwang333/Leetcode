class Solution {
    bool isPalindrome(string s){
        for(int i=0; i<s.size()/2; i++){
            if(s[i] != s[s.size()-i-1]){
                return false;
            }
        }
        return true;
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ret;
        unordered_map<int, vector<int>> m;
        for(int i=0; i<s.size(); i++){
            for(int j=1; j<=s.size()-i; j++){
                if(isPalindrome(s.substr(i, j))){
                    m[i].push_back(j);
                }
            }
        }
        queue<vector<string>> q;
        q.push(vector<string>{});
        queue<int> q2;
        q2.push(0);
        while(!q.empty()){
            int sz = q.size();
            for(int i=0; i<sz; i++){
                int tmp = q2.front();
                q2.pop();
                vector<string> tmp2 = q.front();
                q.pop();
                if(tmp == s.size()){
                    ret.push_back(tmp2);
                    continue;
                }
                for(int j:m[tmp]){
                    vector<string> tmp3 = tmp2;
                    tmp3.push_back(s.substr(tmp,j));
                    q.push(tmp3);
                    int tmp4 = tmp + j;
                    q2.push(tmp4);

                }
            }
        }
        return ret;
    }
};
