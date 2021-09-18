class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ret;
        vector<int> v;
        queue<vector<int>> q;
        ret.push_back(v);
        for(int i=0; i<n; i++){
            while(!q.empty()){
                q.pop();
            }
            v.clear();
            v.push_back(nums[i]);
            ret.push_back(v);
            q.push(v);
            for(int j=i+1; j<n; j++){
                int qsize = q.size();
                queue<vector<int>> qtmp = q;
                for(int z=0; z<qsize; z++){
                    v = q.front();
                    q.pop();
                    v.push_back(nums[j]);
                    ret.push_back(v);
                    q.push(v);
                }
                while(!qtmp.empty()){
                    q.push(qtmp.front());
                    qtmp.pop();
                }
            }
        }
        return ret;
    }
};
