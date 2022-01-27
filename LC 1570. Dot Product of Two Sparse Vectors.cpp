class SparseVector {
public:
    unordered_map<int, int> m;
    
    SparseVector(vector<int> &nums) {
        for(int i=0; i<nums.size(); i++){
            if(nums[i] != 0){
                m[i] = nums[i];
            }
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int ret = 0;
        for(auto it = m.begin(); it != m.end(); it++){
            ret += vec.m[it->first]*it->second;
        }
        return ret;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);
