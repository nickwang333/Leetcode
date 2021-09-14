class Solution {
public:
    int maxNumberOfBalloons(string text) {
        map<char, int> m;
        for(char i:text){
            m[i]++;
        }
        int ret = min(min(m['b'], m['a']),m['n']);
        ret = min(min(ret, m['o']/2),m['l']/2);
        return ret;
    }
};
