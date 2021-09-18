class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        vector<int> v;
        ret.push_back(v);
        queue<vector<int>> q;
        int n = nums.size();
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
                    queue<vector<int>> tmpq = q;
                    for(int k = 0; k<qsize; k++){
                        v = q.front();
                        v.push_back(nums[j]);
                        ret.push_back(v);
                        q.pop();
                        q.push(v);
                    }
                    while(!tmpq.empty()){
                        q.push(tmpq.front());
                        tmpq.pop();
                    }
                }
        }
        map<vector<int>, int> m;
        for(auto i:ret){
            m[i]++;
        }
        ret.clear();
        for(auto it=m.begin(); it!=m.end(); it++){
            ret.push_back(it->first);
        }
        return ret;
    }
};
