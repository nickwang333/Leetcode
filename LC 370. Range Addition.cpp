class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> ret(length,0), tmp(length+1,0);
        for(auto i:updates){
            tmp[i[0]] += i[2];
            tmp[i[1]+1] -= i[2];
        }
        for(int i=0; i<ret.size(); i++){
            if(i==0){
                ret[0] = tmp[0];
            }
            else{
                ret[i] = ret[i-1]+tmp[i];
            }
        }
        return ret;
    }
};
