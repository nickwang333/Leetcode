class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        int n = colors.size();
        vector<int> c1(n,-1), c2(n,-1), c3(n,-1);
        for(int i=0; i<n; i++){
            if(i==0){
                if(colors[i]==1){c1[i] = 0;}
                else if(colors[i]==2){c2[i] = 0;}
                else{c3[i] = 0;}
            }
            else{
                if(colors[i]==1){
                    c1[i] = 0;
                    if(c2[i-1]==-1){c2[i]=-1;}
                    else{c2[i]=c2[i-1]+1;}
                    if(c3[i-1]==-1){c3[i]=-1;}
                    else{c3[i]=c3[i-1]+1;}
                }
                else if(colors[i]==2){
                    c2[i] = 0;
                    if(c1[i-1]==-1){c1[i]=-1;}
                    else{c1[i]=c1[i-1]+1;}
                    if(c3[i-1]==-1){c3[i]=-1;}
                    else{c3[i]=c3[i-1]+1;}
                }
                else{
                    c3[i] = 0;
                    if(c1[i-1]==-1){c2[i]=-1;}
                    else{c1[i]=c1[i-1]+1;}
                    if(c2[i-1]==-1){c2[i]=-1;}
                    else{c2[i]=c2[i-1]+1;}
                }
            }
        }
        for(int i=n-1; i>=0; i--){
            if(i==n-1){
                if(colors[i]==1){c1[i] = 0;}
                else if(colors[i]==2){c2[i] = 0;}
                else{c3[i] = 0;}
            }
            else{
                if(colors[i]==1){
                    c1[i] = 0;
                    if(c2[i+1]==-1){c2[i]=-1;}
                    else if(c2[i]==-1){c2[i]=c2[i+1]+1;}
                    else{c2[i]=min(c2[i], c2[i+1]+1);}
                    if(c3[i+1]==-1){c3[i]=-1;}
                    else if(c3[i]==-1){c3[i]=c3[i+1]+1;}
                    else{c3[i]=min(c3[i], c3[i+1]+1);}
                }
                else if(colors[i]==2){
                    c2[i] = 0;
                    if(c1[i+1]==-1){c1[i]=-1;}
                    else if(c1[i]==-1){c1[i]=c1[i+1]+1;}
                    else{c1[i]=min(c1[i], c1[i+1]+1);}
                    if(c3[i+1]==-1){c3[i]=-1;}
                    else if(c3[i]==-1){c3[i]=c3[i+1]+1;}
                    else{c3[i]=min(c3[i], c3[i+1]+1);}
                }
                else{
                    c3[i] = 0;
                    if(c2[i+1]==-1){c2[i]=-1;}
                    else if(c2[i]==-1){c2[i]=c2[i+1]+1;}
                    else{c2[i]=min(c2[i], c2[i+1]+1);}
                    if(c1[i+1]==-1){c1[i]=-1;}
                    else if(c1[i]==-1){c1[i]=c1[i+1]+1;}
                    else{c1[i]=min(c1[i], c1[i+1]+1);}
                }
            }
        }
        vector<int> ret;
        for(auto i:queries){
            if(i[1]==1){
                ret.push_back(c1[i[0]]);
            }
            else if(i[1]==2){
                ret.push_back(c2[i[0]]);
            }
            else{
                ret.push_back(c3[i[0]]);
            }
        }
        return ret;
    }
};
