class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int n = 0;
        unordered_map<int, int> m;
        for(int i:tasks){
            m[i]++;
        }
        for(auto i:m){
            if(i.second < 2){
                return -1;
            }
            else{
                n += i.second / 3;
                if(i.second % 3 > 0){
                    n++;
                }
            }
        }
        return n;
    }
};
