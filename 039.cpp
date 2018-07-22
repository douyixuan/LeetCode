class Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		int n=candidates.size();
		vector<vector<int>> ans;
		vector<int> res;
	   // 
		sort(candidates.begin(),candidates.end());
	   //
	   // for(int i=0;i<n;i++)
		sanmao(candidates,0,target,ans,res);
		return ans;
	}
	void sanmao(vector<int>& cand, int i, int rem, vector<vector<int>>& ans, vector<int> res){
	   // ans.push_back(res);
		if(rem<0) return ;
		if(rem==0) ans.push_back(res);

		for(i;i<cand.size();i++){
			res.push_back(cand[i]);
			sanmao(cand,i,rem-cand[i],ans,res);// bug
			res.pop_back();
		}

		return;
	}
};
/*
- recursion 
there are many different patterns
where to enter next layer is the key;
in other words, what is the order really matters
- bug happened here, cause i can control tmporary cand[i]'s show times.
and it can also enter into next cand[i+1] by i++ operation.
*/