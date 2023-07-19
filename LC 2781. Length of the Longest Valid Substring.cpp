class Solution {
    
public:
    int longestValidSubstring(string word, vector<string>& forbidden) {
        unordered_map<string, int> m1, m2;
        int n = word.size(), last = 0, ret = 0;
        for(string i:forbidden){
            m1[i] = 1;
        }
        for(int i=0; i<n; i++){
            int flag = 0;
            string tmp = "";
            tmp += word[i];
            if(m1[tmp] == 1){
                last = i+1;
                continue;
            }
            for(int j=1; j<=min(i-last+1,10); j++){
                if(i-j+1 >= 0 && m1[word.substr(i-j+1,j)] == 1){
                    flag = 1;
                    last = i-j+2;
                    break;
                }
            }
            if(flag == 0){
                ret = max(ret, i-last+1);
                //cout << i << " " << word.substr(i-ret+1, ret) << endl;
            }
        }
        return ret;
    }
};
