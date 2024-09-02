class Solution {
public:
    bool checkTwoChessboards(string coordinate1, string coordinate2) {
        int tmp1 = coordinate1[0] - 'a';
        int tmp2 = coordinate1[1] - '0';
        int tmp3 = coordinate2[0] - 'a';
        int tmp4 = coordinate2[1] - '0';
        int total = tmp1 + tmp2 + tmp3 + tmp4;
        return total%2 == 0;
    }
};
