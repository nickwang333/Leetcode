class Solution {
public:
    int minSetSize(vector<int>& arr) {
        map<int,int> m;
        int n = arr.size(), tsum = 0;
        vector<int> dp;
        for(int i:arr){
            m[i]++;
        }
        for(auto i:m){
            dp.push_back(i.second);
        }
        sort(dp.rbegin(), dp.rend());
        for(int i=0; i<dp.size(); i++){
            tsum += dp[i];
            if(tsum >= n/2){
                return i+1;
            }
        }
        return -1;
    }
};
