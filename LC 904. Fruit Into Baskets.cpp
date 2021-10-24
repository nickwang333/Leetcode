class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int size = 0, sp = 0, ret = 1;
        map<int, int> m;
        for(int i=0; i<tree.size(); i++){
            m[tree[i]]++;
            if(m[tree[i]]==1){
                size++;
                if(size==3){
                    while(size!=2){
                        m[tree[sp]]--;
                        if(m[tree[sp]]==0){
                            size--;
                        }
                        sp++;
                    }
                }
            }
            ret = max(ret, i-sp+1);
        }
        return ret;
        
    }
};
