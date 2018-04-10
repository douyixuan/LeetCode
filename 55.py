#!/usr/bin/python

class Solution(object):
	def canJump(self, nums):
		"""
		:type nums: List[int]
		:rtype: bool
		"""
		l = len(nums)
		pos = l-1
		i = pos
		while i>=0:
			if nums[i]+i >= pos:
				pos = i
			i = i - 1
		print(pos)
		return pos == 0
"""
可以随便print
不影响
哈哈哈
贪心：
不断缩小范围
为了全局
逐个遍历
"""
nums = input()
s = Solution()
s.canJump(nums)