class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0" || num2=="0"){
            return "0";
        }
        int m = num1.size(), n = num2.size(), carry=0, prev = 0;
        vector<int> v(m+n-1,0);
        for(int i=0; i<m; i++){
            int tmp1 = num1[i]-'0';
            for(int j=0; j<n; j++){
                int tmp2 = num2[j]-'0';
                v[i+j] += tmp2*tmp1;
            }
        }
        string ret;
        for(int i=m+n-2; i>=0; i--){
            int tmp3 = v[i]+carry;
            carry = tmp3/10;
            int digit = tmp3%10;
            ret += (digit+'0');
        }
        if(carry!=0){
            ret+=(carry+'0');
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
