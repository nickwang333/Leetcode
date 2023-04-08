/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<int, Node*> m1;
        unordered_map<int, vector<int>> m2;
        unordered_map<int, int> visited;
        queue<Node*> q;
        if(!node){
            return NULL;
        }
        q.push(node);
        while(!q.empty()){
            Node* tmp = q.front();
            q.pop();
            visited[tmp->val] = 1;
            vector<int> tmpv;
            for(auto i:tmp->neighbors){
                if(visited[i->val] == 0){
                    q.push(i);
                }
                tmpv.push_back(i->val);
            }
            m2[tmp->val] = tmpv;
        }
        for(auto i:m2){
            m1[i.first] = new Node(i.first);
        }
        for(auto i:m2){
            vector<Node*> v;
            for(int j:i.second){
                v.push_back(m1[j]);
            }
            m1[i.first]->neighbors = v;
        }
        return m1[1];
    }
};
