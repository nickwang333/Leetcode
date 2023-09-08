class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret;
        vector<int> v{1};
        for(int i=0; i<numRows; i++){
            if(i == 0){
                ret.push_back(v);
            }
            else{
                int sz = v.size();
                vector<int> tmp(sz+1);
                tmp[sz] = 1;
                tmp[0] = 1;
                for(int j=1; j<sz; j++){
                    tmp[j] = v[j-1] + v[j];
                }
                v = tmp;
                ret.push_back(v);
            }
        }
        return ret;
    }
};
