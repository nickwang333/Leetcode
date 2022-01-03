class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int ret = 0, maxi;
        sort(properties.begin(), properties.end());
        map<int, vector<int>> m;
        for(auto i:properties){
            m[i[0]].push_back(i[1]);
        }
        for(auto it = m.rbegin(); it != m.rend(); it++){
            if(it==m.rbegin()){
                maxi = it->second[it->second.size()-1];
            }
            else{
                for(int j=0; j<it->second.size(); j++){
                    if(it->second[j] < maxi){
                        ret++;
                    }
                    else{
                        maxi = it->second[j];
                    }
                }
            }
        }
        return ret;
    }
};
