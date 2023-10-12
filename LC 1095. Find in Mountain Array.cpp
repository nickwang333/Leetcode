/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int ret = -1, n = mountainArr.length(), high = n-1, low = 0, mid, peak;
        while(high > low){
            mid = (high-low)/2 + low;
            if(mountainArr.get(mid) < mountainArr.get(mid+1)){
                low = mid+1;
            }
            else{
                high = mid;
            }
        }
        peak = low;
        high = low;
        low = 0;
        while(high > low){
            mid = (high-low)/2 + low;
            if(mountainArr.get(mid) < target){
                low = mid+1;
            }
            else{
                high = mid;
            }
        }
        if(mountainArr.get(low) == target){
            return low;
        }
        high = n-1;
        low = peak;
        while(high > low){
            mid = (high-low)/2 + low;
            if(mountainArr.get(mid) > target){
                low = mid+1;
            }
            else{
                high = mid;
            }
        }
        if(mountainArr.get(low) == target){
            return low;
        }
        else{
            return -1;
        }
    }
};
