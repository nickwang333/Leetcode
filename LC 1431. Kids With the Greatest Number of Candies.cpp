class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n = candies.size(), maxi = candies[0];
        vector<bool> ret(n);
        for(int i=0; i<n; i++){
            maxi = max(maxi, candies[i]);
        }
        for(int i=0; i<n; i++){
            if((candies[i]+extraCandies) >= maxi){
                ret[i] = true;
            }
            else{
                ret[i] = false;
            }
        }
        return ret;
    }
};
