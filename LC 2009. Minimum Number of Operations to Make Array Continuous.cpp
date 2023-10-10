class Solution {
public:
    int minOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), ret = n;
        map<int, int> m;
        for(int i=0; i<n; i++){
            m[nums[i]]++;
        }
        auto sp = m.begin();
        int counter = 0;
        for(auto it:m){
            int begin = it.first;
            while(sp != m.end() && sp->first <= begin+n-1){
                counter++;
                sp++;
            }
            ret = min(ret, n-counter);
            //cout << counter << " ";
            counter--;
        }
        return ret;
    }
};
