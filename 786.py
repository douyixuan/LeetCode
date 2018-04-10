#!/usr/bin/python

class Solution(object):
	def kthSmallestPrimeFraction(self, A, K):
		"""
		:type A: List[int]
		:type K: int
		:rtype: List[int]
		"""
		ans = ()
		cur = 0
		l = len(A)
		for i in range(0,l):
			for j in range(i+1,l):
				ans[cur] = [A[j]/A[i],A[i],A[j]]
				cur = cur+1
		ans.sort(key = lambda x:x['x'])
		return {ans[k-1][1],ans[k-1][2]}
			
			