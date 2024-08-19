class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        unordered_map<int, int> hor, ver;
        priority_queue<int> q;
        long long ret = 0;
        int hori = 1, vert = 1;
        for(int i:horizontalCut){
            hor[i]++;
            q.push(i);
        }
        for(int i:verticalCut){
            ver[i]++;
            q.push(i);
        }
        while(!q.empty()){
            int tmp = q.top();
            q.pop();
            if(hor[tmp] > 0){
                hor[tmp]--;
                ret += (vert * tmp);
                hori++;
            }
            else{
                ver[tmp]--;
                ret += (hori * tmp);
                vert++;
            }
        }
        return ret;
    }
};
