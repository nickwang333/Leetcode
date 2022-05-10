class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> v{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        map<string, int> m;
        for(string i:words){
            string tmp = "";
            for(char j:i){
                tmp += v[j-'a'];
            }
            m[tmp]++;
        }
        return m.size();
    }
};
