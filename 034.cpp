class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		int l=0,r=nums.size()-1;
		vector<int> res;
		res.push_back(r);
		res.push_back(-1);
		if(nums.size()==0) return res;//bug 0
		int ans=-1;//
		while(l<=r){
			int m=(l+r)/2;
			if(nums[m]==target){ans=m;break;}//need?
			else if(nums[m]>target) r=m-1;
			else l=m+1;
		}
		while(nums[ans]==target&&ans>=0){// bug2
			res[0]=min(res[0],ans);
			ans--;
		}
		ans++;
		while(nums[ans]==target&&ans<nums.size()){
			res[1]=max(res[0],ans);
			ans++;// bug 1
		}
		if(res[1]==-1) res[0]=-1;
		return res;
	}
};
/*
- special judge need consider
- leak ans==0 this situation
- the ++ operation 
*/