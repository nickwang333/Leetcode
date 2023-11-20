class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        vector<string> ret;
        unordered_map<string, vector<int>> m;
        for(auto i:access_times){
            m[i[0]].push_back(stoi(i[1]));
        }
        for(auto i:m){
            sort(i.second.begin(), i.second.end());
            for(int j=2; j<i.second.size(); j++){
                if((i.second[j] - i.second[j-2]) < 100){
                    ret.push_back(i.first);
                    break;
                }
            }
        }
        return ret;
    }
};
