class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        unordered_map<int, unordered_map<int, int>> m;
        unordered_map<int, int> m2;
        for(auto i:pick){
            m[i[0]][i[1]]++;
            if(m[i[0]][i[1]] > i[0]){
                m2[i[0]] = 1;
            }
        } 
        return m2.size();
    }
};
