class Solution {
public:
    string addStrings(string num1, string num2) {
        int carry = 0, m = num1.size(), n = num2.size(), i = m-1, j = n-1;
        string ret;
        while(i>=0 || j>=0){
            if(i>=0 && j>=0){
                int tmp = carry+(num1[i]-'0')+(num2[j]-'0');
                ret += (tmp%10+'0');
                carry = tmp/10;
                i--; j--;
            }
            else if(i>=0){
                int tmp = carry+(num1[i]-'0');
                ret += (tmp%10+'0');
                carry = tmp/10;
                i--;
            }
            else{
                int tmp = carry+(num2[j]-'0');
                ret += (tmp%10+'0');
                carry = tmp/10;
                j--;
            }
        }
        if(carry==1){
            ret+='1';
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
