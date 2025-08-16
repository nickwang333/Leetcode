class Solution {
public:
    int maximum69Number (int num) {
        string tmp = to_string(num);
        int n = tmp.size(), fp = -1, sp = -1;
        for(int i=0; i<n; i++){
            if(tmp[i] == '6'){
                tmp[i] = '9';
                return stoi(tmp);
            }
        }
        return num;
    }
};
