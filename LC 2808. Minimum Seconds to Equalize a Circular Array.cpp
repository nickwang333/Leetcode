class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
        unordered_map<int, vector<int>> m;
        unordered_map<int, int> prev;
        int n = nums.size(), ret = n/2;
        for(int i=0; i<n; i++){
            m[nums[i]].push_back(i);
            if(m[nums[i]].size() > 1){
                int tmp1 = m[nums[i]][0];
                int tmp2 = m[nums[i]][m[nums[i]].size()-2];
                int tmp3 = max((n-i+tmp1), (i-tmp2));
                if(m[nums[i]].size() == 2){
                    tmp3 = max(i-tmp1, n-i+tmp1);
                }
                
                tmp3 = max(tmp3, prev[tmp2]);
                prev[i] = max(prev[tmp2], i-tmp2);
                //cout << (n-i+tmp1) << " "<< (tmp2) << " " << tmp3 <<  endl;
                ret = min(ret, tmp3/2);
            }
        }
        return ret;
    }
};
