/**
 * Definition for polynomial singly-linked list.
 * struct PolyNode {
 *     int coefficient, power;
 *     PolyNode *next;
 *     PolyNode(): coefficient(0), power(0), next(nullptr) {};
 *     PolyNode(int x, int y): coefficient(x), power(y), next(nullptr) {};
 *     PolyNode(int x, int y, PolyNode* next): coefficient(x), power(y), next(next) {};
 * };
 */

class Solution {
public:
    PolyNode* addPoly(PolyNode* poly1, PolyNode* poly2) {
        PolyNode* tmp1 = poly1, *tmp2 = poly2;
        map<int, int> m;
        PolyNode* ret = NULL;
        while(tmp1){
            m[tmp1->power] += tmp1->coefficient;
            tmp1 = tmp1->next;
        }
        while(tmp2){
            m[tmp2->power] += tmp2->coefficient;
            tmp2 = tmp2->next;
        }
        for(auto i:m){
            cout << i.first << "  " << i.second << endl;
        }
        PolyNode* tmp3 = ret;
        for(auto it=m.rbegin(); it != m.rend(); it++){
            if(it->second != 0){
                if(!ret){
                    ret = new PolyNode(it->second, it->first);
                    tmp3 = ret;
                }
                else{
                    tmp3->next = new PolyNode(it->second, it->first);
                    tmp3 = tmp3->next;
                }
            }
        }
        return ret;
    }
};
