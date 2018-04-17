class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		int n= nums.size();
		sort(nums.begin(),nums.end());
		int ans=1<<30;
		int res;
		for(int k=0;k<n-2;k++){
			if(k>0 && nums[k]==nums[k-1]) continue;
			int i=k+1,j=n-1,val=target-nums[k];
			while(i<j){
				int su = nums[i]+nums[j]+nums[k];
				if(ans>abs(nums[i]+nums[j]-val)){
					ans=abs(nums[i]+nums[j]-val);
					res=su;
					//bug 0
					//break;
				}
				if(su<target)i++;
				else if(su>target)j--;
				else return target;
				//else j--;
			}
		}
		return res;
	}
};
/*
- k = 0~n-2
- forget the same round may update many times so shouldn't break
- in doing so, containing the change into the condition---if(ans<=abs(nums[i]+nums[j]-val))
*/
