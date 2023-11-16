class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        unordered_map<int, int> m;
        for(string i:nums){
            int tmp = 0;
            for(int j=0; j<n; j++){
                int tmp2 = i[j]- '0';
                tmp += (pow(2, n-j-1) *tmp2);
            }
            m[tmp] = 1;
        }
        string ret(n, '0');
        int tmp = -1;
        for(int i=0; i<pow(2,n); i++){
            if(m[i] == 0){
                tmp = i;
                break;
            }
        }
        for(int i=0; i<n; i++){
            ret[i] = tmp%2 + '0';
            tmp /= 2;
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
