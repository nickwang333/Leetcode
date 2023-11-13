class Solution {
public:
    string sortVowels(string s) {
        string ret = s;
        vector<char> v;
        int counter = 0;
        for(char i:s){
            if(i == 'a' || i == 'A' || i == 'e' ||i == 'E' || i == 'i' || i == 'I' ||i == 'o' ||i == 'O' ||i == 'u' ||i == 'U'){
                v.push_back(i);
                ret[counter] = ' ';
            }
            counter++;
        }
        sort(v.begin(), v.end());
        counter = 0;
        for(int i=0; i<s.size(); i++){
            if(ret[i] == ' '){
                ret[i] = v[counter];
                counter++;
            }
        }
        return ret;
    }
};
