class Solution {
public:
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
        int high = 1e9, low = 0, mid, ret = -1;
        while(high >= low){
            int flag = 0;
            mid = low + (high-low) / 2;
            for(auto i:composition){
                long long total = 0;
                long long total_cost = 0;
                for(int j=0; j<n; j++){
                    total = (long long)(mid)*(long long)(i[j]);
                    if(total <= stock[j]){
                        continue;
                    }
                    total -= stock[j];
                    total = max(total, 0ll);
                    total_cost += total * (long long)(cost[j]);
                }
                if(total_cost <= budget){
                    flag = 1;
                    break;
                }
            }
            if(flag == 1){
                ret = mid;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return ret;
    }
};
