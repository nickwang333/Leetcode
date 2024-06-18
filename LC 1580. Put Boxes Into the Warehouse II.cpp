class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
        vector<int> space = warehouse, space2 = warehouse;
        int n = warehouse.size(), tmp = warehouse[0], ret = 0;
        for(int i=1; i<n; i++){
            space[i] = min(space[i], tmp);
            tmp = space[i];
        }
        tmp = warehouse[n-1];
        for(int i=n-2; i>=0; i--){
            space2[i] = min(space2[i], tmp);
            tmp = space2[i];
        }
        map<int, int> m;
        for(int i=0; i<n; i++){
            m[max(space[i], space2[i])]++;
        }
        sort(boxes.begin(), boxes.end());
        for(int i:boxes){
            auto it = m.lower_bound(i);
            if(it != m.end()){
                cout << it->first << " ";
            }
            if(it != m.end() && it->second > 0){
                it->second--;
                if(it->second == 0){
                    m.erase(it->first);
                }
                ret++;
            }
        }
        return ret;
    }
};
