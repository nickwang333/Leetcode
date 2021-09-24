class Solution {
public:
    vector<int> partitionLabels(string S) {
        map<char, int> m, m2;
        vector<int> ret;
        int counter = 0;
        for(char i:S){
            m[i]++;
        }
        for(char i:S){
            m[i]--;
            counter++;
            if(m[i]==0){
                m2.erase(i);
                if(m2.empty()){
                    ret.push_back(counter);
                    counter = 0;
                }
            }
            else{
                m2[i] = 1;
            }
        }
        return ret;
    }
};
