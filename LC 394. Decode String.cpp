class Solution {
public:
    string decodeString(string s) {
        stack<int> si;
        stack<string> ss;
        string digit, cha, ret;
        for(char i:s){
            if((i-'0')>=0 && (i-'0')<10){
                digit += i;
            }
            else if(i=='['){
                int tmp = stoi(digit);
                si.push(tmp);
                ss.push(ret);
                ret = "";
                digit = "";
            }
            else if(i==']'){
                int tmp = si.top();
                string tmp2 = ss.top();
                ss.pop();
                si.pop();
                for(int i=0; i<tmp; i++){
                    tmp2 = tmp2+ret;
                }
                ret = tmp2;
            }
            else{
                ret += i;
            }
        }
        if(cha != ""){
            ret += cha;
        }
        if(!ss.empty()){
            ret = ss.top()+ret;
        }
        return ret;
    }
};
