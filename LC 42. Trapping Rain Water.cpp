class Solution {
public:
    int trap(vector<int>& height) {
        int ret = 0;
        stack<int> s, s_index;
        for(int i=0; i<height.size(); i++){
            if(s.empty() && height[i] != 0){
                s.push(height[i]);
                s_index.push(i);
            }
            else if(!s.empty() && height[i]<=s.top()){
                s.push(height[i]);
                s_index.push(i);
            }
            else if(!s.empty() && height[i]>s.top()){
                int prev = -1, prev_index = -1, tmp, tmp_index;
                while(!s.empty() && height[i]>=s.top()){
                    tmp = s.top();
                    tmp_index = s_index.top();
                    s.pop();
                    s_index.pop();
                    if(prev == -1){
                        prev = tmp;
                    }
                    else{
                        int diff = tmp - prev;
                        ret += (diff*(i-tmp_index-1));
                    }
                    prev = tmp;
                }
                if(!s.empty()){
                    ret += ((height[i]-prev)*(i-s_index.top()-1));
                }
                
                s.push(height[i]);
                s_index.push(i);
            }
            
        }
        return ret;
    }
};
