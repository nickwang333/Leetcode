class Solution {
public:
    string stringHash(string s, int k) {
        string ret;
        int n = s.size();
        for(int i=0; i<n/k; i++){
            string tmp = s.substr(i * k, k);
            int total = 0;
            for(char i:tmp){
                total += (i-'a');
            }
            total %= 26;
            ret += ('a' + total);
        }
        return ret;
    }
};
