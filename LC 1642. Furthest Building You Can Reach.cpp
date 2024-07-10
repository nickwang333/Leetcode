class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> q;
        int n = heights.size();
        int total = 0;
        for(int i=0; i<n-1; i++){
            if(heights[i] >= heights[i+1]){
                continue;
            }
            else{
                int diff = heights[i+1] - heights[i];
                q.push(-diff);
                
                int tmp = 0;
                if(q.size() <= ladders){
                    continue;
                }
                total -= q.top();
                q.pop();
                if(total > bricks){
                    return i;
                }
            }
        }
        return n-1;
    }
};
