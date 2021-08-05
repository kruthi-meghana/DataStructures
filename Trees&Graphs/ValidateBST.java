/*

Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
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
/*
class ValidateBST {
    public boolean isValidBST(TreeNode root) {
        
        return isBST(root, Long.MIN_VALUE, Long.MAX_VALUE);
    }
    
    public boolean isBST(TreeNode root, long min, long max) {
        if(root == null) return true;
        if(root.val >= max || root.val <= min) return false;
        
        return isBST(root.left, min, root.val) && isBST(root.right, root.val, max);
    }
}*/

class ValidateBST {
    private Integer prev;
    public boolean isValidBST(TreeNode root) {
        prev = null;
        return inorderTraverse(root);
    }
    
    public boolean inorderTraverse(TreeNode root) {
        
        if(root == null) return true;
        if(!inorderTraverse(root.left)) return false;
        if(prev != null && root.val <= prev) return false;
        
        prev = root.val;
        return inorderTraverse(root.right);
    }
    
}
