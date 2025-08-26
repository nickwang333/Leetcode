class Solution {
public:
    int maximumSwap(int num) {
        vector<int> v(10, 0);
        unordered_map<int, vector<int>> pos;
        string s = to_string(num);
        int n = s.size();
        for(int i=0; i<n; i++){
            pos[s[i]-'0'].push_back(i);
            v[s[i]-'0']++;
        }
        int maxi = 0;
        for(int i=9; i>=0; i--){
            if(v[i] > 0){
                maxi = i;
                break;
            }
        }
        for(int i=0; i<n; i++){
            if(s[i]-'0' == maxi){
                v[maxi]--;
                while(maxi >= 0 && v[maxi] == 0){
                    maxi--;
                }
            }
            else{
                int index = pos[maxi].size();
                swap(s[i], s[pos[maxi][index-1]]);
                return stoi(s);
            }
        }
        return num;
    }
};
