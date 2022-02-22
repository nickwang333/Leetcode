class Solution {
public:
    int titleToNumber(string columnTitle) {
        int n = columnTitle.size(), ret = 0;
        for(char i:columnTitle){
            ret = (i-'A'+1)+26*ret;
        }
        return ret;
    }
};
