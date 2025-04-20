class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> m;
        int ret = 0;
        for(int i:answers){
            auto it = m.find(i);
            if(it != m.end()){
                if(it->first+1 == it->second){
                    ret++;
                    ret += i;
                    m[i] = 1;
                }
                else{
                    m[i]++;
                }
            }
            else{
                ret++;
                ret += i;
                m[i] = 1;
            }
        }
        return ret;
    }
};
