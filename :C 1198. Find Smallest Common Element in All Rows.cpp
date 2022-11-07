class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        map<int,int> m2;
        for(auto i:mat){
            for(int j:i){
                m2[j]++;
            }
        }
        for(auto it:m2){
            if(it.second == m){
                return it.first;
            }
        }
        cout << m2[5];
        return -1;
    }
};
