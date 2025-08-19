class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        queue<vector<int>> q;
        int n = nums.size(), curr = 1;
        q.push(vector<int>{});
        for(int i=0; i<n; i++){
            int sz = q.size();
            for(int j=0; j<sz; j++){
                vector<int> tmp = q.front();
                q.pop();
                q.push(tmp);
                if(i > 0 && nums[i-1] == nums[i]){
                    int sz2 = tmp.size();
                    if(sz2 >= curr && tmp[sz2 - curr] == nums[i]){
                        tmp.push_back(nums[i]);
                        q.push(tmp);
                    }
                }
                else{
                    tmp.push_back(nums[i]);
                    q.push(tmp);
                }
            }
            if(i > 0 && nums[i-1] == nums[i]){
                curr++;
            }
            else{
                curr =1;
            }
        }
        while(!q.empty()){
            ret.push_back(q.front());
            q.pop();
        }
        return ret;
    }
};
