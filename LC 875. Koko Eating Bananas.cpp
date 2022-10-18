class Solution {
    bool valid(vector<int>& piles, int n, int mid){
        int ret = 0;
        for(int i:piles){
            if(i%mid == 0){
                ret += i/mid;
            }
            else{
                ret += (i/mid)+1;
            }
        }
        return ret <= n;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = piles[0], mini = 1;
        for(int i:piles){
            maxi = max(maxi, i);
        }
        while(maxi>mini){
            int mid = (maxi-mini)/2 + mini;
            if(valid(piles, h, mid)){
                maxi = mid;
            }
            else{
                mini = mid+1;
            }
        }
        return maxi;
    }
};
