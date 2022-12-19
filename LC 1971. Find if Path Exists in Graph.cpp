class Solution {
    public boolean validPath(int n, int[][] edges, int source, int destination) {
        Map<Integer, ArrayList<Integer>> hm = new HashMap<>();
        for(int i=0; i<edges.length; i++){
            hm.computeIfAbsent(edges[i][0], val -> new ArrayList<Integer>()).add(edges[i][1]);
            hm.computeIfAbsent(edges[i][1], val -> new ArrayList<Integer>()).add(edges[i][0]);
        }
        boolean[] visited = new boolean[n];
        for(int i=0; i<n; i++){
            visited[i] = false;
        }
        Queue<Integer> q = new LinkedList<>();
        q.add(source);
        while(!q.isEmpty()){
            int tmp = q.poll();
            if(tmp == destination){
                return true;
            }
            visited[tmp] = true;
            for(int i:hm.get(tmp)){
                if(!visited[i]){
                    q.add(i);
                }
            }
        }
        return false;
    }
}
