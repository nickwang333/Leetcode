class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size(), m = nums2.size(), i1 = 0, i2 = 0;
        unordered_map<int, unordered_map<int, int>> visited;

        vector<vector<int>> ret;
        long tmpp = long(m)*long(n);
        long tmpk = k;
        if(tmpp < tmpk){
            k = m*n;
        }
        priority_queue<int> q;
        unordered_map<int, queue<vector<int>>> m1;
        q.push(-nums1[0]-nums2[0]);
        visited[0][0] = 1;
        m1[-nums1[0]-nums2[0]].push(vector<int> {0,0});
        for(int i=0; i<k; i++){
            int tmp = q.top();
            q.pop();
            vector<int> tmp2 = m1[tmp].front();
            vector<int> tmp4{nums1[tmp2[0]], nums2[tmp2[1]]};
            ret.push_back(tmp4);
            m1[tmp].pop();
            if(tmp2[0] < n-1 && visited[tmp2[0]+1][tmp2[1]] == 0){
                int tmpsum = nums1[tmp2[0]+1] + nums2[tmp2[1]];
                visited[tmp2[0]+1][tmp2[1]] = 1;
                vector<int> tmp3{tmp2[0]+1, tmp2[1]};
                m1[-tmpsum].push(tmp3);
                q.push(-tmpsum);
            }
            if(tmp2[1] < m-1 && visited[tmp2[0]][tmp2[1]+1] == 0){
                int tmpsum = nums1[tmp2[0]] + nums2[tmp2[1]+1];
                visited[tmp2[0]][tmp2[1]+1] = 1;
                vector<int> tmp3{tmp2[0], tmp2[1]+1};
                m1[-tmpsum].push(tmp3);
                q.push(-tmpsum);
            }
        }
        
        return ret;
    }
};
