class Solution {
public:
    string smallestNumber(long long n) {
        vector<int> v;
        if(n == 1){
            return "1";
        }
        while(n > 1){
            int flag = 0;
            for(int i=9; i>1; i--){
                if(n % i == 0){
                    n /= i;
                    v.push_back(i);
                    flag = 1;
                    break;
                }
            }
            if(flag == 0){
                return "-1";
            }
        }
        sort(v.begin(), v.end());
        string ret;
        for(auto i:v){
            ret += to_string(i);
        }
        return ret;
    }
};
