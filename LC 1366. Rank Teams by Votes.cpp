class Solution {
public:
    string rankTeams(vector<string>& votes) {
        int n = votes.size(), m = votes[0].size();
        unordered_map<char, map<int, int>> count;
        // 26 n 
        for(string i:votes){
            for(int j=0; j<i.size(); j++){
                count[i[j]][j]++;
            }
        }
        //["ABC","ACB","ABC","ACB","ACB"]
        // A:       1: 5;       2: 0;       3: 0 -> 5 0 0
        // B:       1: 0;       2: 2;       3: 3 -> 022B
        // C:       1: 0;       2: 3;       3: 2 -> 022C
        // A, Z; B, Y
        // ACB -> ABC
        vector<string> v;
        for(auto i:count){
            string tmp;
            for(int j=0; j<m; j++){
                if(i.second[j] < 10){
                    tmp += "000";
                    tmp += (i.second[j] + '0');
                }
                else if(i.second[j] < 100){
                    tmp += "00";
                    tmp += to_string(i.second[j]);
                }
                else if(i.second[j] < 1000){
                    tmp += "0";
                    tmp += to_string(i.second[j]);
                }
                else{
                    tmp += to_string(i.second[j]);
                }
            }
            tmp += ('A' + (25 - (i.first-'A')));
            v.push_back(tmp);
        }
        string ret;
        sort(v.begin(), v.end());
        for(string i:v){
            char tmp2 = i[i.size()-1];
            tmp2 = ('A' + (25 - (tmp2-'A')));
            ret += tmp2;
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
