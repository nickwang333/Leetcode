class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int ret = 0;
        queue<int> q;
        for(int i:nums){
            int n = q.size();
            for(int j=0; j<n; j++){
                int tmp = q.front();
                q.pop();
                q.push(tmp);
                q.push(tmp^i);
            }
            q.push(i);
        }
        while(!q.empty()){
            ret += q.front();
            q.pop();
        }
        return ret;
    }
};
