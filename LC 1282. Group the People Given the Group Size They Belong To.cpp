class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> ret;
        unordered_map<int, int> pos;
        int counter1 = 0, counter2 = 0;
        for(auto i:groupSizes){
            auto it = pos.find(i);
            if(it == pos.end()){
                vector<int> v;
                ret.push_back(v);
                pos[i] = counter2;
                counter2++;
                ret[pos[i]].push_back(counter1);
                if(ret[pos[i]].size() == i){
                    pos.erase(i);
                }
            }
            else{
                ret[pos[i]].push_back(counter1);
                if(ret[pos[i]].size() == i){
                    pos.erase(i);
                }
            }
            counter1++;
        }
        return ret;
    }
};
