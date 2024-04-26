#include<vector>
#include<functional>
using namespace std;
class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
	
        const int dir[5] = {-1,0,1,0,-1};
        int root[m*n];
        memset(root,-1,sizeof(root));
        int count=  0;
		
        function<int(int)>find = [&](int x){
            if(root[x]!=x){
                return root[x] = find(root[x]);
            }
            return x;
        };
		
        function<bool(int,int)>unionSet = [&](int a ,int b){
            int rA = find(a),rB = find(b);
            if(rA==rB)
                return true;
            root[rA] = rB;
            count--;
            return false;
        };
		
        vector<int>ans;
        for(vector<int>&v:positions){
            int curr = v[0]*n+v[1];
            if(root[curr]==-1){
                count++;
                 root[curr] = curr;
            }
            for(int i = 0;i<4;i++){
                int x = v[0]+dir[i],y=  v[1]+dir[i+1];
                if(x>=0&&x<m&&y>=0&&y<n&&(x*n+y)<m*n&&root[x*n+y]!=-1){
                    unionSet(curr,x*n+y);
                        
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};
