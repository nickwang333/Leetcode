class Solution {
public:
    int minimumPushes(string word) {
        vector<int> v(26,0);
        int ret = 0;
        for(char i:word){
            v[i-'a']++;
        }
        sort(v.rbegin(), v.rend());
        for(int i=0; i<26; i++){
            if(i < 8){
                ret += v[i];
            }
            else if(i < 16){
                ret += (v[i] * 2);
            }
            else if(i < 24){
                ret += (v[i] * 3);
            }
            else{
                ret += (v[i] * 4);
            }
        }
        return ret;
    }
};
