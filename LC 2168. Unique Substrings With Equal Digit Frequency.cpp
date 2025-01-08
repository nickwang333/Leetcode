class Solution {
public:
    bool isEqual(vector<int>& v){
        int prev = -1;
        for(int i=0; i<10; i++){
            if(v[i] != 0 && prev == -1){
                prev = v[i];
            }
            else if(v[i] != 0 && prev != v[i]){
                return false;
            }
        }
        return true;
    }

    int equalDigitFrequency(string s) {
        unordered_map<string, int> ans;
        int n = s.size();
        for(int i=0; i<n; i++){
            string tmp = "";
            vector<int> v(10, 0);
            for(int j=i; j<n; j++){
                tmp += s[j];
                v[s[j]-'0']++;
                if(isEqual(v)){
                    ans[tmp] = 1;
                }
            }
        }
        return ans.size();
    }
};
