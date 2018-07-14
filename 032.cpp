class Solution {
public:
	int longestValidParentheses(string s) {
		int n = s.size();
		stack<pair<char,int> > san;
		int to[100010]={0};//bug 0
		for(int i=0;i<n;i++){
			if(s[i]=='(') san.push((pair<char,int>){s[i],i});
			else if(s[i]==')' && !san.empty()){
				pair<char,int> p = san.top();
				if(p.first=='('){
					to[p.second]=i+1;
					to[i]=p.second;
					san.pop();
				}
				else{
					san.push((pair<char,int>){s[i],i});
				}
			}
			else{
				san.push((pair<char,int>){s[i],i});
			}
		}
		int ans=0;
		for(int i=0;i<n;i++){
			int p=to[i];
			while(to[p]>p && p<n){//which one operate first
				p=to[p];
			}
			ans=max(ans,p-i);
		}
		return ans;
	}
};
/*
- memset 0 ,it's necessary
- condition, completely.
*/