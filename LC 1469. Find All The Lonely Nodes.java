/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public List<Integer> getLonelyNodes(TreeNode root) {
        List<Integer> list = new ArrayList<>();
        Queue<TreeNode> q = new LinkedList<>();
        HashMap<TreeNode, List<TreeNode>> parent = new HashMap<>();
        q.add(root);
        while(!q.isEmpty()){
            TreeNode tmp = q.poll();
            if(tmp.left != null){
                q.add(tmp.left);
                List<TreeNode> listVal = new ArrayList<>();
                if(parent.containsKey(tmp)){
                    listVal = parent.get(tmp);
                }
                listVal.add(tmp.left);
                parent.put(tmp, listVal);
            }
            if(tmp.right != null){
                q.add(tmp.right);
                List<TreeNode> listVal;
                if(parent.containsKey(tmp)){
                    listVal = parent.get(tmp);
                    listVal.add(tmp.right);
                }
                else{
                    listVal = new ArrayList<>();
                    listVal.add(tmp.right);
                }
                parent.put(tmp, listVal);
            }
        }
        for(TreeNode key:parent.keySet()){
            if(parent.get(key).size() == 1){
                list.add(parent.get(key).get(0).val);
            }
        }
        return list;
    }
}
