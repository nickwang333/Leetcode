class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        int n = words.size(), ret = 0;
        vector<int> used(n, 0);
        reverse(words.begin(), words.end());
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                string tmp = words[j];
                reverse(tmp.begin(), tmp.end());
                if(used[i] == 0 && used[j] == 0 && words[i] == tmp){
                    ret++;
                    used[i] = 1;
                    used[j] = 1;
                    break;
                }
            }
        }
        return ret;
    }
};
