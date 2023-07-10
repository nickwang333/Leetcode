class Solution {
public:
    int minimumBeautifulSubstrings(string s) {
        
        // Power of 5: 1, 101, 11001, 1001110001, 110000110101, 11110100001001
        // length: 1, 3, 5, 10, 12, 14
        
        // "10110111111011"
        int n = s.size();
        vector<string> matching_string{"11110100001001", "110000110101", "1001110001", "1111101", "11001", "101", "1"};
        vector<int> v(n+1, -1);
        v[0] = 0;
        for(int i=0; i<n; i++){
            if(v[i] != -1){
                for(string j:matching_string){
                    int tmp = j.size();
                    if((i+tmp) <= s.size() && (s.substr(i, tmp) == j)){
                        if(v[i+tmp] == -1){
                            v[i+tmp] = v[i] + 1;
                        }
                        else{
                            v[i+tmp] = min(v[i+tmp], v[i]+1);
                        }
                    }
                }
            }
        }
        return v[n];
        
    }
};
