class Solution {
public:
    int minimumBuckets(string street) {
        int ret = 0, n = street.size();
        for(int i=0; i<n; i++){
            if(street[i] == 'H'){
                if(i!=0){
                    if(street[i-1]=='B'){
                        continue;
                    }
                }
                if(i==n-1){
                    if(i==0 || street[i-1] == 'H'){
                        return -1;
                    }
                    if(street[i-1]=='.'){
                        ret++;
                    }
                }
                if(i+1<n && street[i+1] == '.'){
                    ret++;
                    street[i+1] = 'B';
                }
                else if(i+1<n && street[i+1] == 'H'){
                    if(i==0 || street[i-1] == 'H'){
                        return -1;
                    }
                    if(street[i-1] == '.'){
                        ret++;
                    }
                }
            }
        }
        return ret;
    }
};
