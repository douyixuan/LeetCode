class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		int n=nums.size();
		sort(nums.begin(),nums.end());
		set<vector<int> > res;
		for(int i=0;i<n-3;i++){
			for(int j=i+1;j<n-2;j++){
				//can decrease the time
				//if (j > 0 && nums[j] == nums[j - 1]) continue;
				int l=j+1,r=n-1;
				int val = target - nums[i] - nums[j];
				while(l<r){
					int su = nums[l]+nums[r];
					if(su==val){
						res.insert((vector<int>){nums[i],nums[j],nums[l],nums[r]});
						l++;
						r--;
					}
					else if(su>val) r--;
					else l++;
				}
			}
		}
		vector<vector<int>> ans;
		for(set<vector<int>>::iterator it=res.begin();it!=res.end();it++){
			ans.push_back(*it);
		}
		return ans;
		//simplify 
		//return vector<vector<int>>(res.begin(),res.end());
	}
};
/*
- TLE : Oh my god. cause I mistake the variable l-r for i-j 
*/