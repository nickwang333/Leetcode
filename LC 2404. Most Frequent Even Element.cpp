class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int,int> m;
        int ret = -1;
        for(int i:nums){
            if(i%2 == 0){
                m[i]++;
                if(ret == -1 || m[ret] < m[i] || (m[ret] == m[i] && ret > i)){
                    ret = i;
                }
            }
        }
        return ret;
    }
};
