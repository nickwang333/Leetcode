class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        queue<vector<int>> q;
        q.push(vector<int>{});
        int n = nums.size();
        for(int i=0; i<n; i++){
            int sz = q.size();
            for(int j=0; j<sz; j++){
                vector<int> tmp = q.front();
                q.push(tmp);
                q.pop();
                tmp.push_back(nums[i]);
                q.push(tmp);
            }
        }
        while(!q.empty()){
            vector<int> tmp = q.front();
            ret.push_back(tmp);
            q.pop();
        }
        return ret;
    }
};
