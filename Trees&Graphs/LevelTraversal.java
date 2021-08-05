/*
Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).
@author: Kruthi Meghana Anumandla
*/

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
class LevelTraversal {
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        depthFS(root, 1, result);
        return result;
    }
    
    public void depthFS(TreeNode root, int height, List<List<Integer>> result) {
        if(root == null)return;
        
        if(result.size() < height) {
            result.add(new LinkedList<Integer>());
        }
        result.get(height-1).add(root.val);
        depthFS(root.left, height+1, result);
        depthFS(root.right, height+1, result);
    }
}
