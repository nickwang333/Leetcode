class Solution {
public:
    
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        vector<int> ret = queries;
        map<int, int> m;
        for(auto i:items){
            if(m[i[0]]!=0){
                m[i[0]] = max(m[i[0]], i[1]);
            }
            else{
                m[i[0]] = i[1];
            }
        }
        int tmp = 0;
        for(auto it = m.begin(); it!=m.end(); it++){
            if(tmp==0){
                tmp = it->second;
            }
            else{
                it->second = max(it->second, tmp);
                tmp =  max(it->second, tmp);
            }
        }
        vector<int> tmp2;
        for(auto it = m.begin(); it!=m.end(); it++){
            tmp2.push_back(it->first);
        }
        for(int i=0; i<queries.size(); i++){
            auto it = lower_bound(tmp2.begin(), tmp2.end(), queries[i]);
            //cout << *it;
            if(it == tmp2.end()){
                ret[i] = m[tmp2[tmp2.size()-1]];
            }
            else if(*it == queries[i]){
                ret[i] = m[*it];
            }
            else if(it == tmp2.begin() && *it>queries[i]){
                ret[i] = 0;
            }
            else if(it == tmp2.begin()){
                ret[i] = m[*it];
            }
            else{
                it--;
                ret[i] = m[*it];
            }
        }
        return ret;
    }
};
