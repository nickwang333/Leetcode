class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q;
        for(int i:stones){
            q.push(i);
        }

        while(q.size() > 1){
            int tmp1 = q.top();
            q.pop();
            int tmp2 = q.top();
            q.pop();
            if(tmp1 != tmp2){
                q.push(abs(tmp1-tmp2));
            }
            else{
                q.push(0);
            }
        }
        return q.top();
    }
};
