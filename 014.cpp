class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		int n=nums.size();
		sort(nums.begin(),nums.end());
		vector<vector<int> > ans;
		for(int k=0;k<n&& nums[k]<=0;k++){
			if(k>0 && nums[k]==nums[k-1]) continue;
			// bug 0
			int i=k+1,j=n-1;
			int val = 0-nums[k];
			while(i<j){
				if(nums[i]+nums[j]==val){
					ans.push_back({nums[k],nums[i],nums[j]});
					//bug 1
					while(i<j && nums[i]==nums[i+1]) i++;
					while(i<j && nums[j]==nums[j-1]) j--;
					i++;j--;
				}
				else if(nums[i]+nums[j]<val) i++;
				else j--;
			}
		}
		
		return ans;
	}
};
/*
- simply the serach complexity using the properties 
- sum equals 0 means k is the min,then i & j is larger than k,
so if the answer permutation is sorted, then it won't be duplicate
- and so k is small or equal to 0
- another duplicate probablity is continous num is the same, so jump them
*/