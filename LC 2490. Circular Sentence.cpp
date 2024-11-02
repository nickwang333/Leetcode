class Solution {
public:
    bool isCircularSentence(string sentence) {
        vector<string> v;
        string tmp;
        for(char i:sentence){
            if(i == ' '){
                v.push_back(tmp);
                tmp = "";
            }
            else{
                tmp += i;
            }
        }
        v.push_back(tmp);
        int n = v.size();
        for(int i=1; i<n; i++){
            if(v[i][0] != v[i-1][v[i-1].size()-1]){
                return false;
            }
        }
        return v[0][0] == v[n-1][v[n-1].size()-1];
    }
};
