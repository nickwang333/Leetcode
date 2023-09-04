class Solution {
public:
    int minimumOperations(string num) {
        int n = num.size(), ret = n;
        // 00 25 50 75 
        reverse(num.begin(), num.end());
        unordered_map<int, vector<int>> m;
        for(int i=0; i<n; i++){
            m[num[i]-'0'].push_back(i);
        }
        if(m[0].size() > 1){
            ret = min(ret, m[0][1]-1);
        }
        if(m[0].size() > 0){
            for(int i:m[5]){
                if(i > m[0][0]){
                    ret = min(ret, i-1);
                }
            }
        }
        if(m[5].size() > 0){
            for(int i:m[2]){
                if(i > m[5][0]){
                    ret = min(ret, i-1);
                }
            }
        }
        if(m[5].size() > 0){
            for(int i:m[7]){
                if(i > m[5][0]){
                    ret = min(ret, i-1);
                }
            }
        }
        if(num.size() == 2 && num[0] == '0'){
            ret = min(ret, 1);
        }
        if(m[0].size() > 0){
            ret = min(ret, n-1);
        }
        return ret;
    }
};
