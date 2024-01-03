class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prev = 0, ret = 0, m = bank.size(), n = bank[0].size();
        for(int i=0; i<m; i++){
            int tmp = 0;
            for(int j=0; j<n; j++){
                tmp += bank[i][j] - '0';
            }
            ret += tmp*prev;
            if(tmp != 0){
                prev = tmp;
            }
        }
        return ret;
    }
};
