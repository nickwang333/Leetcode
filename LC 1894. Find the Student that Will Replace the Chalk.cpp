class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long total = 0, n = chalk.size();
        for(int i:chalk){
            total += i;
        }
        k %= total;
        for(int i=0; i<n; i++){
            k -= chalk[i];
            if(k < 0){
                return i;
            }
        }
        return -1;
    }
};
