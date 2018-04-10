class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int m = nums1.size(), n = nums2.size();
		return (findKth(nums1, nums2, (m + n + 1) / 2) + findKth(nums1, nums2, (m + n + 2) / 2)) / 2.0;
	}
	int findKth(vector<int> nums1, vector<int> nums2, int k) {
		int m = nums1.size(), n = nums2.size();
		//make sure nums2's size bigger than nums1
		if(m>n) return findKth(nums2,nums1,k);
		//nums1 has no elements
		if(m==0) return nums2[k-1];
		//all in all there are two elements
		/**
		I still can not make sure what does it means
		*/
		if(k==1) return min(nums1[0],nums2[0]);
		//binary search 
		int i=min(m,k/2), j=min(n,k/2);
		if(nums1[i-1]>nums2[j-1]){
			return findKth(nums1,vector<int>(nums2.begin()+j,nums2.end()),k-j);
		}else{
			return findKth(vector<int>(nums1.begin()+i,nums1.end()),nums2,k-i);
		}
		return 0;
	}
};
// I forgot three "return "  so the answer is "WA".