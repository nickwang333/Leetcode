class Solution {
public:
    bool isStrobogrammatic(string num) {
        unordered_map<char, char> m;
        m['0'] = '0';
        m['1'] = '1';
        m['6'] = '9';
        m['8'] = '8';
        m['9'] = '6';
        int n = num.size();
        for(int i=0; i<n/2+1; i++){
            auto it = m.find(num[i]);
            auto it2 = m.find(num[n-i-1]);
            if(it == m.end() || it2 == m.end()){
                return false;
            }
            if(m[num[i]] != num[n-i-1]){
                return false;
            }
        }
        return true;
    }
};
