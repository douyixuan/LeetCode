class Solution {
public:
	// bug 1
	char f[10][4]={
			{},
			{},
			{'a','b','c'},
			{'d','e','f'},
			{'g','h','i'},
			{'j','k','l'},
			{'m','n','o'},
			{'p','q','r','s'},
			{'t','u','v'},
			{'w','x','y','z'}
		};
	vector<string> ans;
	vector<string> letterCombinations(string digits) {
		int n = digits.size();
		fun(0,digits,"",n);
		// bug 2
		if(digits=="") return (vector<string>){};
		return ans;
	}
	void fun(int i,string d,string s,int n){
		if(i==n)  ans.push_back(s);
		int j=0;
		while(i<n && j<4){
			int num = d[i]-'0';
			//bug 0
			if(!f[num][j]) break;
			s.push_back(f[num][j]);
			fun(i+1,d,s,n);
			s.pop_back();
			j++;
		}
		return;
	}
};
/*
- No zuo no die why you try;
- In fact, if I use string [] dict ={"abc","def",...} is better.
- If so, the length of letters is countable, no need to special judge the j-th digit is ''
- The bug of the special input "" is gross. I don't know if it happens using dict;
- substr(indexOfBegin, length)
- substr(index)
*/