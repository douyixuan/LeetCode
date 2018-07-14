/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {


	private Set<TreeNode> set = new HashSet<>();
	private TreeNode ans = null;
		
	public TreeNode subtreeWithAllDeepest(TreeNode root) {
		
		ans = null;
		set.clear();
		int maxDepth = maxDepth(root);
		mark(root , 1 , maxDepth);
		solve(root);
		return ans;
		
	}
	
	private int solve(TreeNode root) {
		
		if (root == null) {
			return 0;
		} else {
			int total = solve(root.left) + solve(root.right);
			if (set.contains(root)) {
				total ++;
			}
			if (total == set.size()) {
				if (ans == null) {
					ans = root;
				}
			}
			return total;
		}
		
	}
	
	private int maxDepth(TreeNode root) {
		
		if (root == null) {
			return 0;
		} else {
			int h1 = maxDepth(root.left) + 1;
			int h2 = maxDepth(root.right) + 1;
			return Math.max(h1 , h2);
		}
		
	}
	
	private void mark(TreeNode root , int depth , int maxDepth) {
		
		if (root.left == null && root.right == null) {
			if (depth == maxDepth) {
				set.add(root);
			}
		} else {
			if (root.left != null) {
				mark(root.left , depth + 1 , maxDepth);
			}
			if (root.right != null) {
				mark(root.right , depth + 1 , maxDepth);
			}
		}
		
	}
}