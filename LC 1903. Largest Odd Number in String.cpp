class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size(), flag = 0;
        string ret;
        for(int i=n-1; i>=0; i--){
            if(flag == 1){
                ret += num[i];
            }
            else{
                int tmp = num[i]-'0';
                if(tmp % 2 == 1){
                    flag = 1;
                    ret += num[i];
                }
            }
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
