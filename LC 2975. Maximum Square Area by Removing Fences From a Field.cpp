class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        int ret = -1;
        unordered_map<int, int> m1, m2;
        for(int i=0; i<hFences.size(); i++){
            m1[hFences[i]-1] = 1;
            m1[m-hFences[i]] = 1;
            for(int j=i+1; j<hFences.size(); j++){
                m1[abs(hFences[i] - hFences[j])] = 1;
            }
        }
        m1[m-1] = 1;
        m2[n-1] = 1;
        for(int i=0; i<vFences.size(); i++){
            m2[vFences[i]-1] = 1;
            m2[n-vFences[i]] = 1;
            for(int j=i+1; j<vFences.size(); j++){
                m2[abs(vFences[i] - vFences[j])] = 1;
            }
        }
        for(auto it = m1.begin(); it != m1.end(); it++){
            if(m2[it->first] == 1){
                ret = max(ret, it->first);
            }
        }
        if(ret == -1){
            return -1;
        }
        return long(ret)*long(ret)%long(1000000007);
    }
};
