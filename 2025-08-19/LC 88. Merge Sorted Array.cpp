class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int fp = m-1, sp = n-1, end = m+n-1;
        for(int i=m+n-1; i>=0; i--){
            if(sp == -1) {
                nums1[i] = nums1[fp];
                end--;
                fp--;
            }
            else if(fp == -1){
                nums1[i] = nums2[sp];
                sp--;
                end--;
            }
            else if(nums1[fp] >= nums2[sp]){
                nums1[end] = nums1[fp];
                end--;
                fp--;
            }
            else{
                nums1[end] = nums2[sp];
                sp--;
                end--;
            }
        }
    }
};
