class Solution {
public:
    bool areNumbersAscending(string s) {
        int n = s.size();
        string tmp = "";
        vector<string> v;
        for(char i:s){
            if(i == ' '){
                v.push_back(tmp);
                tmp = "";
            }
            else{
                tmp += i;
            }
        }
        v.push_back(tmp);
        int prev = 0;
        for(string i:v){
            if(i.size()>0 && isdigit(i[0])){
                int tmp2 = stoi(i);
                if(tmp2<=prev){
                    return false;
                }
                prev = tmp2;
            }
        }
        return true;
    }
};
