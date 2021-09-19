class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ret;
        for(auto i:intervals){
            if(ret.empty()){
                ret.push_back(i);
            }
            else{
                vector<int> tmp = ret[ret.size()-1];
                if(tmp[1]>=i[0]){
                    tmp[1] = max(i[1], tmp[1]);
                    ret[ret.size()-1] = tmp;
                }
                else{
                    ret.push_back(i);
                }
            }
        }
        return ret;
    }
};
