class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ret;
        int begin = 0, sz = target.size();
        stack<int> s;
        for(int i=1; i<=n; i++){
            if(begin >= sz){
                break;
            }
            s.push(i);
            ret.push_back("Push");
            if(s.top() != target[begin]){
                ret.push_back("Pop");
            }
            else{
                begin++;
            }
        }
        return ret;
    }
};
