class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int counter = 0, n = s.size();
        string ret;
        vector<int> v(n+1, 0);
        for(auto i:shifts){
            if(i[2] == 1){
                v[i[0]]++;
                v[i[1]+1]--;
            }
            else{
                v[i[0]]--;
                v[i[1]+1]++;
            }
        }
        for(int i=0; i<n; i++){
            counter += v[i];
            counter %= 26;
            if(counter < 0){
                counter += 26;
            }
            int tmp = counter + (s[i] - 'a');
            tmp += 26;
            tmp %= 26;
            ret += ('a' + tmp);
        }
        return ret;
    }
};
