class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int ret = 0;
        unordered_map<int, vector<int>> m;
        queue<int> q1, q2;
        q1.push(1);
        q2.push(1);
        m[0].push_back(0);
        while(!q1.empty()){
            int tmp1 = q1.front(), tmp2 = q2.front();
            q1.pop();
            q2.pop();
            m[tmp2].push_back(tmp1);
            if(tmp1 <= 1000){
                q1.push(tmp1*2);
                q2.push(tmp2);
                q1.push(tmp1*2+1);
                q2.push(tmp2+1);
            }
        }
        for(auto i:m[k]){
            if(i < nums.size()){
                ret += nums[i];
            }
        }
        return ret;
    }
};
