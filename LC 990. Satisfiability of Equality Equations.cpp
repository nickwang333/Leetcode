class Solution {
    int find_parents(int i, vector<int>& parents){
        int tmp = i;
        while(parents[tmp] != tmp){
            tmp = parents[tmp];
        }
        return tmp;
    }
public:
    bool equationsPossible(vector<string>& equations) {
        vector<int> parents(26,-1);
        for(int i=0; i<26; i++){
            parents[i] = i;
        }
        for(auto i:equations){
            if(i[1] == '='){
                if(find_parents(i[0]-'a', parents) != find_parents(i[3]-'a', parents)){
                    parents[find_parents(i[0]-'a', parents)] = find_parents(i[3]-'a', parents);
                }
            }
        }
        for(auto i:equations){
            if(i[1] == '!'){
                if(find_parents(i[3]-'a', parents) == find_parents(i[0]-'a', parents)){
                    return false;
                }
            }
        }
        return true;
    }
};
