class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		int n=nums.size();
		int l=0,r=n-1,m;
		int ans=0;
		while(l<=r){
			m=(r+l)/2;
			if(nums[m]==target) {ans=m;break;}
			else if(nums[m]>target) r=m-1;
			else l=m+1;
			
		}
		if(nums[m]>target) ans=m;
		else if(nums[m]<target) ans=m+1;
		return ans;
	}
};
/*
- cause nums[m]==target this situation, there is no operation to l,r
the must be a 'break';
- (l+r)/2 is always equal to the left one, the smalller one
*/