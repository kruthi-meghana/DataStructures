/*
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).
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
class SymmetricBST {
    public boolean isSymmetric(TreeNode root) {
        
        return checkSymmetric(root.left, root.right);
    }
    
    public boolean checkSymmetric(TreeNode leftN, TreeNode rightN) {
        if((leftN == null && rightN == null)) return true;
        if(leftN==null || rightN == null) return false;
        if(leftN.val != rightN.val) return false;
        return checkSymmetric(leftN.left, rightN.right) && checkSymmetric(leftN.right, rightN.left);
    }
}
