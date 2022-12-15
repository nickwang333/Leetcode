 class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> m;
        map<int, vector<char>> m2;
        string ret = "";
        for(char i:s){
            m[i]++;
        }
        for(auto i:m){
            m2[i.second].push_back(i.first);
        }
        for(auto i = m2.rbegin(); i != m2.rend(); i++){
            for(char j:i->second){
                for(int z = 0; z<m[j]; z++){
                    ret += j;
                }
            }
        }
        return ret;
    }
};
