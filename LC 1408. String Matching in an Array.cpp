class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        unordered_map<string, int> m;
        vector<string> ret;
        for(int i=0; i<words.size(); i++){
            queue<string> q;
            for(int j=0; j<words[i].size(); j++){
                int n = q.size();
                for(int k=0; k<n; k++){
                    string tmp = q.front();
                    q.pop();
                    tmp += words[i][j];
                    q.push(tmp);
                    m[tmp]++;
                }
                string tmp = "";
                tmp += words[i][j];
                q.push(tmp);
                m[tmp]++;
            }
        }
        for(string i:words){
            if(m[i] != 1){
                ret.push_back(i);
            }
        }
        return ret;
    }
};
