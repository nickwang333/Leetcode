class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.size();
        vector<bool> v(n,false);
        string ret;
        stack<int> st;
        int counter = 0;
        for(int i=0; i<n; i++){
            if(s[i]=='('){
                counter++;
                st.push(i);
            }
            else if(s[i]==')'){
                counter--;
                if(counter<0){
                    counter = 0;
                    v[i] = true;
                }
                else{
                    st.pop();
                }
            }
        }
        while(!st.empty()){
            v[st.top()] = true;
            st.pop();
        }
        for(int i=0; i<n; i++){
            if(!v[i]){
                ret += s[i];
            }
        }
        return ret;
    }
};
