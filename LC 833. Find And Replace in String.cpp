class Solution {
public:
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        vector<int> use(S.size(),-1);
        for(int i=0; i<indexes.size(); i++){
            int flag = 1;
            for(int j=0; j<sources[i].size(); j++){
                if(sources[i][j]!=S[indexes[i]+j]){
                    flag = 0;
                    break;
                }
            }
            if(flag == 1){
                for(int j=0; j<sources[i].size(); j++){
                    use[indexes[i]+j] = i;
                }
            }
        }
        string ret;
        int i=0;
        while(i<S.size()){
            if(use[i]==-1){
                ret += S[i];
                i++;
            }
            else{
                ret += targets[use[i]];
                while(i<S.size()-1 && use[i]== use[i+1]){
                    i++;
                }
                i++;
            }
        }
        return ret;
    }
};
