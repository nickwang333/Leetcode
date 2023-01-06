class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n = costs.size(), ret = 0;
        sort(costs.begin(), costs.end());
        for(int i:costs){
            coins-=i;
            ret++;
            if(coins < 0){
                ret--;
                break;
            }
        }
        return ret;
    }
};
