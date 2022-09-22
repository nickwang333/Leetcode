class Solution {
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
        vector<vector<int>> ret;
        for(auto i:intervals){
            if(i[1] <= toBeRemoved[0] || i[0] >= toBeRemoved[1]){
                ret.push_back(i);
            }
            else{
                vector<int> tmp = i;
                if(toBeRemoved[0] < i[1] && toBeRemoved[0] > i[0]){
                    tmp[1] = toBeRemoved[0];
                    ret.push_back(tmp);
                }
                tmp = i;
                if(toBeRemoved[1] > i[0] && toBeRemoved[1] < i[1]){
                    tmp[0] = toBeRemoved[1];
                    ret.push_back(tmp);
                }
            }
        }
        return ret;
    }
};
