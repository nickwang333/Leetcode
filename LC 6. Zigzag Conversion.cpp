class Solution {
public:
    string convert(string s, int numRows) {
        int r = 0, n=s.size();
        if(numRows == 1){
            return s;
        }
        string ret;
        unordered_map<int, vector<char>> m;
        for(int i=0; i<n; i++){
            // 0 
            // 1 5
            // 2 4
            // 3
            
            // 0
            // 1 3
            // 2
            int tmp = i%(2*numRows-2);
            cout << tmp << " ";
            if(tmp >= numRows){
                m[numRows*2-2-tmp].push_back(s[i]);
            }
            else{
                m[tmp].push_back(s[i]);
            }
        }
        for(int i=0; i<=numRows; i++){
            for(char j:m[i]){
                ret += j;
            }
            cout << endl;
        }
        return ret;
    }
};
