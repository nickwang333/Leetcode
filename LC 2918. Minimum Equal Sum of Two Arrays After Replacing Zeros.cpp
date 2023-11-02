class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        int zero1 = 0, zero2 = 0;
        long long tsum1 = 0, tsum2 = 0;
        for(int i:nums1){
            tsum1 += i;
            if(i == 0){
                zero1++;
            }
        }
        for(int i:nums2){
            tsum2 += i;
            if(i == 0){
                zero2++;
            }
        }
        tsum1 += zero1;
        tsum2 += zero2;
        if(zero1 == 0 && tsum1 < tsum2){
            return -1;
        }
        if(zero2 == 0 && tsum2 < tsum1){
            return -1;
        }  
        return max(tsum1, tsum2);
    }
};
