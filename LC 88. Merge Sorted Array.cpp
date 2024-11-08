class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = n+m-1, p2 = n-1, p3 = m-1;
        while(p1 >= 0){
            if(p3 == -1){
                nums1[p1] = nums2[p2];
                p2--;
            }
            else if(p2 == -1){
                nums1[p1] = nums1[p3];
                p3--;
            }
            else if(nums2[p2] > nums1[p3]){
                nums1[p1] = nums2[p2];
                p2--;
            }
            else{
                nums1[p1] = nums1[p3];
                p3--;
            }
            p1--;
        }
    }
};
