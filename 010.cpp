class Solution {
public:
	bool isMatch(string s, string p) {
		if(p.empty()) return s.empty();
		if(p.size()==1){
			if(s.size()>1 || s.empty()) return false;
			if(s.size()==1) return p[0]=='.'||s[0]==p[0];
		}
		if(p[1]!='*'){
			if(s.empty()) return false;
			return (p[0]==s[0]||p[0]=='.')  && (isMatch(s.substr(1),p.substr(1)));
		}
		//repeat
		while(!s.empty() && (p[0]=='.' || p[0]==s[0])){
			//every remove check once
			if(isMatch(s,p.substr(2))) return true;
			s= s.substr(1);
		}
		return isMatch(s,p.substr(2));
	}
};
/*
- I didn't use the Recursion
- can't deal with the every remove operation
- substr(x) x-end
- the mean of problem differ me
- divide situation is the key
- moni 
*/