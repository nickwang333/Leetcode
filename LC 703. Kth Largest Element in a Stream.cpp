class KthLargest {
private:
    int bound;
    priority_queue<int> pq2;
public:
    KthLargest(int k, vector<int>& nums) {
        bound = k;
        sort(nums.rbegin(), nums.rend());
        int n = nums.size();
        for(int i=0; i<min(n, k); i++){
            pq2.push(-nums[i]);
        }
    }
    
    int add(int val) {
        if(pq2.size() < bound){
            pq2.push(-val);
            return -pq2.top();
        }
        int tmp = -pq2.top();
        if(tmp < val){
            pq2.pop();
            pq2.push(-val);
        }
        return -pq2.top(); 
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
