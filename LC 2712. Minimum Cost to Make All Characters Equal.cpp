class Solution {
public:
    long long minimumCost(string s) {
        long long ret = 0;
        int n = s.size();
        if(n == 1){
            return 0;
        }
        if(n%2 == 0){
            if(s[n/2] != s[n/2 - 1]){
                ret += n/2;
            }
            for(int i=1; i<n/2; i++){
                if(s[i] != s[i-1]){
                    ret += i;
                }
            }
            for(int i=n-2; i >= n/2; i--){
                if(s[i] != s[i+1]){
                    ret += n-i-1;
                }
            }
        }
        else if(n%2 == 1){
            if(s[n/2] != s[n/2 -1]){
                ret += n/2;
            }
            if(s[n/2] != s[n/2 + 1]){
                ret += n/2;
            }
            for(int i=1; i<n/2; i++){
                if(s[i] != s[i-1]){
                    ret += i;
                }
            }
            for(int i=n-2; i > n/2; i--){
                if(s[i] != s[i+1]){
                    ret += n-i-1;
                }
            }
        }
        return ret;
    }
};
