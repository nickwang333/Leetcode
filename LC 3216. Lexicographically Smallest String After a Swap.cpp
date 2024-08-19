class Solution {
public:
    string getSmallestString(string s) {
        int n = s.size();
        for(int i=1; i<n; i++){
            int tmp1 = s[i]-'0';
            int tmp2 = s[i-1]-'0';
            int diff = tmp1-tmp2;
            if(diff % 2 == 0){
                if(tmp1 < tmp2){
                    swap(s[i], s[i-1]);
                    return s;
                }
            }
        }
        return s;
    }
};
