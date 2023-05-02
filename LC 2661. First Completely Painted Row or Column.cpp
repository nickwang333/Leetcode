class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int, vector<int>> m;
        int ms = mat.size(), n = mat[0].size();
        vector<int> row(ms,0), col(n,0);
        for(int i=0; i<ms; i++){
            for(int j=0; j<n; j++){
                vector<int> tmp{i, j};
                m[mat[i][j]] = tmp;
            }
        }
        for(int i=0; i<arr.size(); i++){
            row[m[arr[i]][0]]++;
            if(row[m[arr[i]][0]] == n){
                return i;
            }
            col[m[arr[i]][1]]++;
            if(col[m[arr[i]][1]] == ms){
                return i;
            }
        }
        return -1;
    }
};
