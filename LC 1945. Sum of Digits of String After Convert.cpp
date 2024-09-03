class Solution {
public:
    int getLucky(string s, int k) {
        string total;
        for(char i:s){
            int tmp = (i-'a');
            tmp++;
            string tmp2 = to_string(tmp);
            total += tmp2;
        }
        for(int i=0; i<k; i++){
            int tmp = 0;
            string s2 = total;
            for(char j:s2){
                tmp += (j-'0');
            }
            total = to_string(tmp);
        }
        return stoi(total);
    }
};
