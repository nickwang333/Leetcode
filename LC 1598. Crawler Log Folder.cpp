class Solution {
public:
    int minOperations(vector<string>& logs) {
        int level = 0;
        for(auto i:logs){
            if(i == "../"){
                level--;
                level = max(level, 0);
            }
            else if(i == "./"){
                continue;
            }
            else{
                level++;
            }
        }
        return level;
    }
};
