class Solution {
public:
    long long wonderfulSubstrings(string word) {
        long long ret = 0;
        int n = word.size(), odd = 0;
        unordered_map<int, long long> m;
        int current = 0;
        m[current] = 1;
        for(char c:word){
            int tmp2 = pow(2,c-'a');
            current ^= tmp2;
            ret += m[current];
            for(int i=0; i<10; i++){
                int tmp3 = pow(2, i);
                int tmp = current ^ tmp3;
                ret += m[tmp]; 
            }
            m[current]++;
        }
        return ret;
    }
};
