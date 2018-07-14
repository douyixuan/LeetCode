class Solution {
public:
	int search(vector<int>& nums, int target) {
		int l=0, r=nums.size()-1, m;
		while(l<=r){
			m = (l+r)/2;
			if(nums[m]==target) return m;
			else if(nums[m]<target){
				if(nums[m]<nums[r] && target<=nums[r]) l=m+1;
				else r=m-1;
			}
			else{
				if(nums[l]<nums[m] && target>=nums[l]) r=m-1;
				else l=m+1;
			}
		}
		return -1;
	}
};
/*
- A[l]<target<A[r] ensures the sub is ascending;
- return method is worth learning.
- first ensure the sub is ascending.

- correct, AC
*/
class Solution {
public:
	int search(vector<int>& nums, int target) {
		int l=0, r=(int)nums.size()-1, m;
		if(nums.size()==0) return -1;
		while(l<=r){
			m = (l+r)/2;
			if(nums[m]==target) return m;
			else if(nums[m]<nums[r]){//diff
				if(nums[m]<target && target<=nums[r]) l=m+1;//diff
				else r=m-1;
			}
			else{
				if(target<nums[m] && target>=nums[l]) r=m-1;//diff
				else l=m+1;
			}
		}
		return -1;
	}
};
