class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        int sz = queries.size(), tmp = 0;
        vector<int> ret(sz, 0), color(n+2, 0);
        for(int i=0; i<sz; i++){
            int index = queries[i][0], c = queries[i][1];
            if(color[index+1] != 0 && color[index+1] == color[index]){
                tmp--;
            }
            if(color[index+1] != 0 && color[index+1] == color[index+2]){
                tmp--;
            }
            if(c == color[index]){
                tmp++;
            }
            if(c == color[index+2]){
                tmp++;
            }
            color[index+1] = c;
            ret[i] = tmp;
        }
        return ret;
    }
};
