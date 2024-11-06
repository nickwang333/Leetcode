class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> v = nums;
        sort(v.begin(), v.end());
        int prev = -1;
        vector<int> v2;
        vector<vector<int>> v3;
        for(int i=0; i<n; i++){
            int tmp = nums[i], counter = 0;
            while(tmp > 0){
                counter += (tmp%2);
                tmp /= 2;
            }
            if(i == 0 || counter == prev){
                prev = counter;
                v2.push_back(nums[i]);
            }
            else{
                sort(v2.begin(), v2.end());
                v3.push_back(v2);
                v2 = vector<int> {};
                prev = counter;
                v2.push_back(nums[i]);
            }
        }
        sort(v2.begin(), v2.end());
        v3.push_back(v2);
        int counter = 0;
        for(auto i:v3){
            for(int j:i){
                if(v[counter] != j){
                    return false;
                }
                counter++;
            }
        }
        return true;
    }
};
