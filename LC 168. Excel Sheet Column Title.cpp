class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ret;
        if(columnNumber == 1){
            return "A";
        }
        while(columnNumber > 0){
            int tmp2 = (columnNumber-1)%26;
            ret += (tmp2 + 'A');
            columnNumber = (columnNumber-1) / 26;
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
