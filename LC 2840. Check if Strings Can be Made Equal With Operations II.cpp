class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int counter = 0;
        string tmp1, tmp2, tmp3, tmp4;
        for(char i:s1){
            if(counter % 2 == 0){
                tmp1 += i;
            }
            else{
                tmp2 += i;
            }
            counter++;
        }
        counter = 0;
        for(char i:s2){
            if(counter % 2 == 0){
                tmp3 += i;
            }
            else{
                tmp4 += i;
            }
            counter++;
        }
        sort(tmp1.begin(), tmp1.end());
        sort(tmp2.begin(), tmp2.end());
        sort(tmp3.begin(), tmp3.end());
        sort(tmp4.begin(), tmp4.end());
        return tmp1 == tmp3 && tmp2 == tmp4;
    }
};
