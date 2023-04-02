class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        vector<int> ret(n), tmpv = potions;
        sort(tmpv.begin(),  tmpv.end());
        for(int i=0; i<n; i++){
            long long tmp;
            if(success % spells[i] == 0){
                tmp = success / spells[i] -1;
            }
            else{
                tmp = success / spells[i];
            }
            
            auto it = upper_bound(tmpv.begin(), tmpv.end(), tmp);
            if(it == tmpv.end()){
                ret[i] = 0;
            }
            else{
                ret[i] = it - tmpv.begin();
                ret[i] = potions.size() - ret[i];
            }
        }
        cout << potions.size();
        return ret;
    }
};
