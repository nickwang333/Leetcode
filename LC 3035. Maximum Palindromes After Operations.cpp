class Solution {
public:
    int maxPalindromesAfterOperations(vector<string>& words) {
        int n = words.size(), ret = 0;
        vector<int> v(26, 0), sz;
        for(string i:words){
            for(char j:i){
                v[j-'a']++;
            }
            sz.push_back(i.size());
        }
        vector<int> odd;
        for(int i=0; i<26; i++){
            if(v[i] % 2 == 1){
                odd.push_back(i);
            }
        }
        sort(sz.begin(), sz.end());
        for(int i:sz){
            if(i % 2 == 0){
                int tmp = i;
                for(int j=0; j<26; j++){
                    if(v[j] >= tmp){
                        v[j] -= tmp;
                        ret++;
                        break;
                    }
                    else{
                        tmp -= (v[j]/2 *2);
                        v[j] %= 2;
                    }
                }
            }
            else{
                if(odd.size() > 0){
                    v[odd[0]]--;
                    odd.erase(odd.begin(), odd.begin()+1);
                }
                int tmp = i-1;
                for(int j=0; j<26; j++){
                    if(v[j] >= tmp){
                        v[j] -= tmp;
                        ret++;
                        break;
                    }
                    else{
                        tmp -= (v[j]/2 *2);
                        v[j] %= 2;
                    }
                }
            }
        }
        return ret;
    }
};
