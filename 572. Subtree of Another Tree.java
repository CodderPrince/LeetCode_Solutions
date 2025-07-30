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

        // Check if two trees are identical
        public boolean isIdentical(TreeNode root, TreeNode subRoot) {
            /*
             * if root == null and subRoot == null
             * means both trees are empty, so they are identical
             */
            if (root == null && subRoot == null) {
                return true;
            }

            /*
             * if either root == null or subRoot == null
             * then they are not identical because one is null and the other is not
             */
            if (root == null || subRoot == null) {
                return false;
            }

            /*
             * Now, check if root.val == subRoot.val
             * if so, check if both the left and right subtrees are identical
             */
            if (root.val == subRoot.val) {
                return isIdentical(root.left, subRoot.left)
                        && isIdentical(root.right, subRoot.right);
            }

            // If values do not match, return false
            return false;
        }

        // Function to check if subRoot is a subtree of root
        public boolean isSubtree(TreeNode root, TreeNode subRoot) {
            /*
             * If subRoot is null, it's always true because an empty tree is a subtree of any tree
             */
            if (subRoot == null) {
                return true;
            }

            /*
             * If root is null but subRoot is not, it's false because a non-empty tree can't be a subtree of an empty tree
             */
            if (root == null) {
                return false;
            }

            /*
             * If the current nodes' values match, check if they are identical using the isIdentical function
             * If they are identical, return true.
             */
            if (root.val == subRoot.val) {
                if (isIdentical(root, subRoot)) {
                    return true;
                }
            }

            /*
             * If the current nodes' values do not match, or they are not identical, 
             * recursively check if subRoot is a subtree of root's left or right child
             */
            return isSubtree(root.left, subRoot) // Check left subtree
                    || isSubtree(root.right, subRoot); // Check right subtree
        }
    }
