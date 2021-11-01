class Solution {
public:
    string concat(int i, int j){
        if(i==j){
            return to_string(i);
        }
        string ret = to_string(i);
        ret += "->";
        ret += to_string(j);
        return ret;
    }
    
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> ret;
        if(nums.size()==0){
            ret.push_back(concat(lower, upper));
            return ret;
        }
        for(int i=0; i<nums.size(); i++){
            int prev;
            if(i==0){
                prev = lower;
                if(nums[i]-lower != 0){
                    ret.push_back(concat(lower, nums[i]-1));
                }
            }
            else{
                if(nums[i]-1 >= nums[i-1]+1){
                    ret.push_back(concat(nums[i-1]+1, nums[i]-1));
                }
            }
        }
        if(nums[nums.size()-1]<upper){
            ret.push_back(concat(nums[nums.size()-1]+1, upper));
        }
        return ret;
    }
};
