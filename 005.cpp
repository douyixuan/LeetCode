class Solution {
public:
	int p[2020]={0};
	string longestPalindrome(string s) {
		return manacher(s);
	}
	string manacher(string s){
		string t = "@#";
		for(int i=0;i<s.size();i++){
			t+=s[i];
			t+='#';
		}
		int id=0,ansmx=0,ansid=0,mx=0;
		for(int i=1;i<t.size();i++){
			p[i]=mx>i? min(p[2*id-i],mx-i) : 1;
			while(t[i+p[i]]==t[i-p[i]]){ p[i]++;}
			if(mx<i+p[i]){
				mx=p[i];
				id=i;
			}
			if(ansmx<p[i]){
				ansmx=p[i];
				ansid = i;
			}
		}
		return s.substr((ansid-ansmx)/2,ansmx-1);
	}
};
/*
- mx  <  p[i]+i  符号错了，p[i]写错成id*2-i
- substr(beginIdenx,length)
- mx = 0 at initial time
- t from 1 to size()-1
- while(t[i]==t[j])  写错成p
*/