class Solution {
public:
	bool isPalindrome(int x) {
		if(x<0) return false;
		string s="";
		if(x==0) s="0";
		while(x){
			s+='0' + x%10;
			x/=10;
		}
		bool ans = false;
		for(int i=0;i<(s.size()+1)/2;i++){
			if(s[i]==s[s.size()-1-i]){ans=true;}
			else {return false;}
		}
		return ans;
	}
};
/*
- forget the special test "0"
*/