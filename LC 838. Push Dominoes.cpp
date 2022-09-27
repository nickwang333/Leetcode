class Solution {
public:
    string pushDominoes(string dominoes) {
        string ret = dominoes;
        int n = dominoes.size();
        vector<int> v;
        stack<int> s;
        for(int i=0; i<n; i++){
            if(dominoes[i] == 'L'){
                if(!s.empty()){
                    int tmp = s.top();
                    s.pop();
                    for(int j = tmp+1; j<(tmp+i+1)/2; j++){
                        ret[j] = 'R';
                    }
                    for(int j = (tmp+i)/2+1; j<i; j++){
                        ret[j] = 'L';
                    }
                }
                else{
                    for(int j=i-1; j>=0; j--){
                        if(ret[j] == '.'){
                            ret[j] = 'L';
                        }
                        else{
                            break;
                        }
                    }
                }
            }
            else if(dominoes[i] == 'R'){
                if(!s.empty()){
                    int tmp = s.top();
                    s.pop();
                    for(int j = i-1; j>=0; j--){
                        if(ret[j] == '.'){
                            ret[j] = 'R';
                        }
                        else{
                            break;
                        }
                    }
                }
                s.push(i);
            }
        }
        if(!s.empty()){
            for(int i = n-1; i>=0; i--){
                if(ret[i] == '.'){
                    ret[i] = 'R';
                }
                else{
                    break;
                }
            }
        }
        return ret;
    }
};
