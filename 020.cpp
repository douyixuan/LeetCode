class Solution {
public:
	bool isValid(string s) {
		stack<char> res;
		for(int i=0;i<s.size();i++){
			if(s[i]=='(' || s[i]=='[' || s[i]=='{') res.push(s[i]);
			else{
				if(res.empty()) return false;
				if(s[i]==')' && res.top()=='(') res.pop();
				else if(s[i]==']' && res.top()=='[') res.pop();
				else if(s[i]=='}' && res.top()=='{') res.pop();
				else return false;
			}
		}
		return res.empty();
	}
};