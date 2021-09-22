class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size(),count=0;
        
        vector<int> v(1); v[0] = nums[0];
        for(int i=1; i<n; i++){
            if(nums[i]!=nums[i-1]){
                v.push_back(nums[i]);
            }
        }
        for(int i=2; i<v.size(); i++){
            if(((v[i]-v[i-1])*(v[i-1]-v[i-2]))>0){
                count++;
            }
        }
        return v.size()-count;
    }
};
