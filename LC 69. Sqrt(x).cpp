class Solution {
public:
    int mySqrt(int x) {
        int low = 0, high = x, mid;
        if(x < 2){
            return x;
        }
        while(high >= low){
            mid = (high-low)/2 + low;
            if(long(mid) * long(mid) > x){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return low-1;
    }
};
