class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        int n = reward1.size(), ret = 0;
        vector<int> cost(n);
        for(int i=0; i<n; i++){
            cost[i] = reward1[i] - reward2[i];
            ret += reward1[i];
        }
        sort(cost.rbegin(), cost.rend());
        for(int i:cost){
            if(k == 0){
                ret -= i;
            }
            else{
                k--;
            }
        }
        return ret;
    }
};
