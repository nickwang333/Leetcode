class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        vector<int> v(1001,0);
        queue<int> q;
        for(int i=2; i<=1000; i++){
            if(v[i] == 0){
                for(int j=2; j*i<=1000; j++){
                    v[j*i] = 1;
                }
            }
        }
        for(int i=0; i<nums.size(); i++){
            for(int j=nums[i]-1; j>=2; j--){
                if(v[j] == 0){
                    if(i == 0){
                        nums[i] -= j;
                        break;
                    }
                    else{
                        if(nums[i]-j > nums[i-1]){
                            nums[i] -= j;
                            break;
                        }
                    }
                }
            }
        }
        for(int i=1; i<nums.size(); i++){
            if(nums[i] <= nums[i-1]){
                return false;
            }
        }
        return true;
    }
};
