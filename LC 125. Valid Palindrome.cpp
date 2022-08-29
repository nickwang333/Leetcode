class Solution {
public:
    bool isPalindrome(string s) {
        string tmp;
        for(char i:s){
            int tmp1 = i-'a', tmp2 = i-'A', tmp4 = i-'0';
            if(tmp1>=0 && tmp1<26){
                tmp += i;
            }
            if(tmp2>=0 && tmp2<26){
                char tmp3 = tmp2+'a';
                tmp += tmp3;
            }
            if(tmp4 >= 0 && tmp4<10){
                tmp+=i;
            }
        }
        int n = tmp.size(), tail = n-1;
        for(int i=0; i<n/2; i++){
            if(tmp[i] != tmp[tail]){
                return false;
            }
            tail--;
        }
        return true;
    }
};
