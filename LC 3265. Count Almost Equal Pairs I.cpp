class Solution {
public:
    int countPairs(vector<int>& nums) {
        int n = nums.size(), ret = 0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(nums[i] == nums[j]){
                    ret++;
                }
                else{
                    string s1 = to_string(nums[i]);
                    string s2 = to_string(nums[j]);
                    int sz = max(s1.size(), s2.size());
                    int s1size = s1.size(), s2size = s2.size();
                    for(int k=s1size; k<sz; k++){
                        s1 = "0" + s1;
                    }
                    for(int k=s2size; k<sz; k++){
                        s2 = "0" + s2;
                    }
                    int diff = 0;
                    for(int k=0; k<sz; k++){
                        if(s1[k] != s2[k]){
                            diff++;
                        }
                    }
                    sort(s1.begin(), s1.end());
                    sort(s2.begin(), s2.end());
                    if(s1 == s2 && diff <= 2){
                        ret++;
                    }
                }
            }
        }
        return ret;
    }
};
