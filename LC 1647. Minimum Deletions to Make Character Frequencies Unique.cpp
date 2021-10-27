class Solution {
public:
    int minDeletions(string s) {
        vector<long> v(26,0);
        map<int, int> m;
        for(char i:s){
            v[i-'a']++;
        }
        int next = 0, ret = 0;
        sort(v.begin(), v.end());
        for(int i=0;i<26;i++){
            if(v[i]!=0){
                m[v[i]]++;
                if(m[v[i]]==2){
                    m[v[i]]--;
                    int index = v[i]-1;
                    while(m[index]!=0){
                        index--;
                    }
                    ret += (v[i]-index);
                    if(index!=0){
                       m[index]++;
                    }
                }
            }
        }        
        return ret;
    }
};
