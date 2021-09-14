class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size(), low = 0, high = n-1;
        long ret = 0;
        while(high > low){
            long tmp = (high-low)*min(height[high],height[low]);
            ret = max(ret,tmp);
            if(height[high] > height[low]){
                low++;
            }
            else{
                high--;
            }
        }
        return ret;
    }
};
