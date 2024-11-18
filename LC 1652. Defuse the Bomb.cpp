class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ret(n, 0);
        if(k == 0){
            return ret;
        }
        int begin, end;
        if(k < 0){
            begin = n+k;
            end = n-1;
        }
        else if(k > 0){
            begin = 1;
            end = k;
        }
        int tmp = begin, total = 0;
        
        while(tmp != end){
            total += code[tmp];
            tmp++;
            tmp %= n;
        }
        total += code[end];
        
        ret[0] = total;
        for(int i=1; i<n; i++){
            total -= code[begin];
            begin++;
            begin%=n;
            end++;
            end%=n;
            total += code[end];
            ret[i] = total;
        }
        return ret;
    }
};
