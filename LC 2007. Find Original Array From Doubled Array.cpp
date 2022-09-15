class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        vector<int> ret, v(0);
        map<int,int> m;
        for(int i:changed){
            m[i]++;
        }
        for(auto it = m.begin(); it != m.end(); it++){
            if(it->first == 0){
                int n = it->second;
                for(int i=0; i<n/2; i++){
                    m[it->first] %= 2;
                    ret.push_back(it->first);
                }
            }
            else if(it->second > 0){
                int n = it->second;
                m[it->first * 2] -= m[it->first];
                m[it->first] = 0;
                for(int i=0; i<n; i++){
                    ret.push_back(it->first);
                }
            }
        }
        for(auto i:m){
            if(i.second != 0){
                return v;
            }
        }
        return ret;
    }
};
