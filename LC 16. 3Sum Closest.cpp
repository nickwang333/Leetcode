class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ret = nums[0] + nums[1] + nums[2], diff = abs(ret-target), n = nums.size();
        for(int i=0; i<n-2; i++){
            int end = n-1, start = i+1, tsum = target - nums[i];
            while(end > start){
                if(nums[start] + nums[end] > tsum){
                    if(diff > abs(tsum - nums[start] - nums[end])){
                        ret = nums[i] + nums[start] + nums[end];
                        //cout << nums[i] << " "<< nums[start] << " " << nums[end] << endl;
                    }
                    end--;
                }
                else if(nums[start] + nums[end] < tsum){
                    if(diff > abs(tsum - nums[start] - nums[end])){
                        ret = nums[i] + nums[start] + nums[end];
                        //cout << nums[i] << " "<< nums[start] << " " << nums[end] << endl;
                    }
                    start++;
                }
                else{
                    return target;
                }
            }
        }
        return ret;
    }
};
