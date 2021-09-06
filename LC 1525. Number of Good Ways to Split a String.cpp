class Solution {
public:
    int numSplits(string s) {
        vector<int> forward(26,0), backward(26,0);
        int c1 = 0, c2 = 0;
        for(char i:s){
            if(forward[i-'a']==0){
                c1++;
            }
            forward[i-'a']++;
        }
        long ret = 0;
        for(char i:s){
            forward[i-'a']--;
            if(forward[i-'a']==0){
                c1--;
            }
            if(backward[i-'a']==0){
                c2++;
            }
            backward[i-'a']++;
            if(c1==c2){
                ret++;
            }
        }
        return ret;
    }
};
