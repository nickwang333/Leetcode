class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size(), candidates, counter = 0, other;
        for(int i:nums){
            if(counter==0){
                candidates = i;
                counter++;
            }
            else{
                if(i==candidates){
                    counter++;
                }
                else{
                    counter--;
                }
            }
        }
        
        return candidates;
    }
};
