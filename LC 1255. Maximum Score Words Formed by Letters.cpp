class Solution {
public:
    bool addable(vector<int>& limit, vector<int>& v, string s){
        vector<int> tmp = v;
        for(char i:s){
            tmp[i-'a']++;
            if(tmp[i-'a'] > limit[i-'a']){
                return false;
            }
        }
        v = tmp;
        return true;
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int ret = 0;
        vector<int> limit(26, 0);
        for(char i:letters){
            limit[i-'a']++;
        }
        queue<vector<int>> q;
        vector<int> v(26,0);
        queue<int> q2;
        q2.push(0);
        q.push(v);
        for(string i:words){
            int n = q.size();
            for(int j=0; j<n; j++){
                vector<int> tmp = q.front();
                q.pop();
                q.push(tmp);
                int tmp2 = q2.front();
                q2.pop();
                q2.push(tmp2);
                if(addable(limit, tmp, i)){
                    for(char c:i){
                        tmp2 += score[c-'a'];
                    }
                    q.push(tmp);
                    q2.push(tmp2);
                    ret = max(ret, tmp2);
                }
            }
        }
        return ret;
    }
};
