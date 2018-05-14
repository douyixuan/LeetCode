class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> ans;
		solve(n,n,"",ans);
		return ans;
	}
	void solve(int l,int r,string res,vector<string> &ans){
		if(l==0 && r==0){
			ans.push_back(res);
			return;
		}
		if(l>r) return;
		if(l) solve(l-1,r,res+'(',ans);
		if(r) solve(l,r-1,res+')',ans);
		
	}
};
/*
- the skill of iterate
1. count and end condition
2. the wrong instance detection
3. global virable record during the process
	using & operator
4. limit or broader prevention

*/