class Solution {
public:
    int numberOfPaths(int n, vector<vector<int>>& corridors) {
        map<int, map<int, int>> m;
        int ret = 0;
        for(auto i:corridors){
            m[i[0]][i[1]] = 1;
            m[i[1]][i[0]] = 1;
        }
        for(auto it = m.begin(); it != m.end(); it++){
            for(auto it2 = it; it2 != m.end(); it2++){
                if(it2 == it){
                    continue;
                }
                if(it->second[it2->first]!=1){
                    continue;
                }
                for(auto it3 = it2->second.begin(); it3 != it2->second.end(); it3++){
                    if(it3->first > it2->first && it3->first > it->first){
                        if(it->second[it3->first]==1){
                            //cout << it->first << " "  << it2->first << " " << it3->first << endl;
                            ret++;
                        }
                    }
                }
            }
        }
        return ret;
    }
};
