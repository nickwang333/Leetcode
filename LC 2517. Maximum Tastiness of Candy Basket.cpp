class Solution {
public:
    bool doable(vector<int>& price, int k, int m){
        // function to check if the m tastiness is feasible
        // O(n)
        int n = price.size(), prev = price[0], count = 1;
        for(int i=1; i<n; i++){
            if(prev + m <= price[i]){
                prev = price[i];
                count++;
            }
        }
        return count >= k;
    }

    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(), price.end());
        // n logn

        int n = price.size(), high = price[n-1] - price[0], low = 0, mid = 0;
        while(high > low){
            // log (high - low) log(10 ^ 9) = 10^4.5 
            mid = (high+low+1) / 2;

            int prev = price[0], count = 1;
            for(int i=1; i<n; i++){
                if(prev + mid <= price[i]){
                    prev = price[i];
                    count++;
                }
            }
            if(count >= k){
                low = mid;
            }
            else{
                high = mid-1;
            }
        }
        return low;
    }
};
