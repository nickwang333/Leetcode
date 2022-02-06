class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int> ret, v1, v2;
        for(int i=0; i<nums.size(); i++){
            if(i%2==0){
                v1.push_back(nums[i]);
            }
            else{
                v2.push_back(nums[i]);
            }
        }
        sort(v1.begin(), v1.end());
        sort(v2.rbegin(), v2.rend());
        int counter1 = 0, counter2 = 0;
        for(int i=0; i<nums.size(); i++){
            if(i%2==0){
                ret.push_back(v1[counter1]);
                counter1++;
            }
            else{
                ret.push_back(v2[counter2]);
                counter2++;
            }
        }
        return ret;
    }
};
