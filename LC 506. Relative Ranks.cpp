class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        map<int, string> m;
        for(int i:score){
            m[i] = "";
        }
        int counter = 0;
        for(auto it = m.rbegin(); it != m.rend(); it++){
            if(counter == 0){
                it->second = "Gold Medal";
            }
            else if(counter == 1){
                it->second = "Silver Medal";
            }
            else if(counter == 2){
                it->second = "Bronze Medal";
            }
            else{
                it->second = to_string(counter+1);
            }
            counter++;
        }
        vector<string> ret(score.size());
        for(int i=0; i<score.size(); i++){
            ret[i] = m[score[i]];
        }
        return ret;
    }
};
