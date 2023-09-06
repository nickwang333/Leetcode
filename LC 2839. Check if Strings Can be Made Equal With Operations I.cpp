class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        string tmp1;
        tmp1 += s1[0];
        tmp1 += s1[2]; 
        string tmp2;
        tmp2 += s1[1];
        tmp2 += s1[3];
        string tmp3;
        tmp3 += s2[0];
        tmp3 += s2[2];
        string tmp4;
        tmp4 += s2[1];
        tmp4 += s2[3];
        sort(tmp1.begin(), tmp1.end());
        sort(tmp2.begin(), tmp2.end());
        sort(tmp3.begin(), tmp3.end());
        sort(tmp4.begin(), tmp4.end());
        return tmp1 == tmp3 && tmp2 == tmp4;
    }
};
