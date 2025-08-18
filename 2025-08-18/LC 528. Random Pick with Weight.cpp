class Solution {
  int total = 0;
  vector<int> v;
public:
    Solution(vector<int>& w) {
        int n = w.size();
        for(int i=0; i<n; i++){
            total += w[i];
            v.push_back(total-1);
        }
    }
    
    int pickIndex() {
        int random = rand() % total;
        int low = 0, high = v.size()-1, mid;
        while(high > low){
            mid = (high-low)/2 + low;
            if(v[mid] < random){
                low = mid+1;
            }
            else{
                high = mid;
            }
        }
        return low;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
