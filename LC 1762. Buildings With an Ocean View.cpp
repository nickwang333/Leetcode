class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        stack<int> s;
        vector<int> ret;
        int n=0;
        for(int i=heights.size()-1; i>=0; i--){
            if(heights[i]>n){
                s.push(i);
                n = heights[i];
            }
        }
        while(!s.empty()){
            ret.push_back(s.top());
            s.pop();
        }
        return ret;
    }
};
