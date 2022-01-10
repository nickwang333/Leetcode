class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int carry = 0;
        string ret;
        for(int i=0; i<min(a.size(), b.size()); i++){
            if(carry == 0){
                if(a[i]==b[i]){
                    ret += '0';
                    if(a[i]=='1'){
                        carry = 1;
                    }
                }
                else{
                    ret += '1';
                }
            }
            else{
                if(a[i]==b[i]){
                    ret += '1';
                    if(a[i]=='0'){
                        carry = 0;
                    }
                }
                else{
                    ret += '0';
                }
            }
        }
        if(a.size()>b.size()){
            for(int i=b.size(); i<a.size(); i++){
                if(carry == 1){
                    if(a[i] == '1'){
                        ret += '0';
                    }
                    else{
                        ret+= '1';
                        carry = 0;
                    }
                }
                else{
                    ret += a[i];
                }
            }
        }
        else{
            for(int i=a.size(); i<b.size(); i++){
                if(carry == 1){
                    if(b[i] == '1'){
                        ret += '0';
                    }
                    else{
                        ret+= '1';
                        carry = 0;
                    }
                }
                else{
                    ret += b[i];
                }
            }
        }
        if(carry == 1){
            ret += '1';
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
