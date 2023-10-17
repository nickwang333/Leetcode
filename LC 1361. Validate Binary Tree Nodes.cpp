class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> parents(n, -1);
        int root = -1;
        
        //construct the parents group 
        for(int i=0; i<n; i++){
            if(leftChild[i] != -1){
                if(parents[leftChild[i]] != -1){
                    return false;
                }
                parents[leftChild[i]] = i;
            }
            if(rightChild[i] != -1){
                if(parents[rightChild[i]] != -1){
                    return false;
                }
                parents[rightChild[i]] = i;
            }
        }
        
        //Check if there is only one root
        for(int i=0; i<n; i++){
            if(parents[i] == -1){
                if(root == -1){
                    root = i;
                }
                else{
                    return false;
                }
            }
        }
        
        //if there is no root, return false;
        if(root == -1){
            return false;
        }
        
        // check if there is right amount of edges
        int edges = 0;
        for(int i=0; i<n; i++){
            if(leftChild[i] != -1){
                edges++;
            }
            if(rightChild[i] != -1){
                edges++;
            }
        }
        if(edges != n-1){
            return false;
        }
        
        //doing a bfs
        vector<int> visited(n, -1);
        queue<int> q;
        q.push(root);
        visited[root] = 0;
        while(!q.empty()){
            int tmp = q.front();
            q.pop();
            if(leftChild[tmp] != -1){
                if(visited[leftChild[tmp]] != -1){
                    return false;
                }
                visited[leftChild[tmp]] = 0;
                q.push(leftChild[tmp]);
            }
            if(rightChild[tmp] != -1){
                if(visited[rightChild[tmp]] != -1){
                    return false;
                }
                visited[rightChild[tmp]] = 0;
                q.push(rightChild[tmp]);
            }
        }
        for(int i:visited){
            if(i == -1){
                return false;
            }
        }
        return true;
    }
};
