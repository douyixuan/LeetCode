#!/usr/bin/python
# Definition for a binary tree node.
class TreeNode(object):
     def __init__(self, x):
         self.val = x
         self.left = None
         self.right = None

class Solution(object):
	
	def constructMaximumBinaryTree(self, nums):
		"""
		:type nums: List[int]
		:rtype: TreeNode
		"""
		'''
		def construct(root,low,high):
			mac = -1000
			j = 0
			for i in range(low,high):
				if mac<num[i]:
					mac = num[i]
					j=i
			root.val = mac
			if low<j:
				root.left = TreeNode(None)
				construct(root.left,low,j)
			if j+1<high:
				root.right = TreeNode(None)
				construct(root.right, j+1, high)
		root=TreeNode(None)
		construct(root, 0, len(nums))
		return root
		'''
		d = TreeNode(None)
		def cons(root,nums):
			if not nums:
				return
			i = nums.index(max(nums))
			root.val = max(nums)
			print(nums)
			if nums[:i]:
				root.left = TreeNode(None)
				cons(root.left, nums[:i])
			if nums[i+1:]:
				root.right = TreeNode(None)
				cons(root.right, nums[i+1:])
		
		cons(d, nums)
		return d
			
nums = input()
s = Solution()
s.constructMaximumBinaryTree(nums)