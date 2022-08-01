class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        map<int, int> m1, m2;
        int tmp1 = node1, tmp2 = node2, counter = 1;
        while(tmp1 != -1){
            if(m1[tmp1] != 0){
                break;
            }
            m1[tmp1] = counter;
            tmp1 = edges[tmp1];
            counter++;
        }
        counter = 1;
        
        while(tmp2 != -1){
            if(m2[tmp2] != 0){
                break;
            }
            m2[tmp2] = counter;
            tmp2 = edges[tmp2];
            counter++;
        }
        int tmpl1 = -1, ret = -1;
        
        for(auto it = m1.begin(); it != m1.end(); it++){
            if(m2[it->first] != 0){
                if(ret == -1){
                    ret = it->first;
                    tmpl1 = max(it->second, m2[it->first]);
                }
                else{
                    int tmp3 = max(it->second, m2[it->first]);
                    if(tmpl1 > tmp3){
                        tmpl1 = tmp3;
                        ret = it->first;
                    }
                }
            }
        }
        return ret;
    }
};
