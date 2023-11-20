class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), ret = 0, ret2 = 1;
        vector<int> flip(n, 0), tmp1 = nums1, tmp2 = nums2;
        for(int i=0; i<n-1; i++){
            if((tmp1[i] > tmp1[n-1]) || (tmp2[i] > tmp2[n-1])){
                int tmp = tmp1[i];
                tmp1[i] = tmp2[i];
                tmp2[i] = tmp;
                ret++;
                flip[i] = 1;
            }
            if((tmp1[i] > tmp1[n-1]) || (tmp2[i] > tmp2[n-1])) {
                return -1;
            }
        }
        int tmp = nums1[n-1];
        nums1[n-1] = nums2[n-1];
        nums2[n-1] = tmp;        
        for(int i=0; i<n-1; i++){
            if((nums1[i] > nums1[n-1]) || (nums2[i] > nums2[n-1])){
                int tmp = nums1[i];
                nums1[i] = nums2[i];
                nums2[i] = tmp;
                ret2++;
            }
            if((nums1[i] > nums1[n-1]) || (nums2[i] > nums2[n-1])) {
                return -1;
            }
        }
        return min(ret2, ret);
    }
};
