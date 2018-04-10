class Solution {
public:
	string convert(string s, int numRows) {
		string ans="";
		if(s.size()==0||s.size()==1||numRows==1) return s;
		for(int i=0;i<s.size();i+=numRows*2-2){
			ans+=s[i];
		}
		for(int i=1;i<numRows-1;i++){
			ans+=zuosige(s,i,numRows);
		}
		for(int i=numRows-1;i<s.size();i+=numRows*2-2){
			ans+=s[i];
		}
		return ans;
	}
	string zuosige(string s,int n,int numRows){
		string tmp="";
		for(int i=n;i<s.size();i+=numRows*2-2){
			tmp+=s[i];
			//here is the key !!!
			if(i+(numRows*2-(n+1)*2)<s.size())tmp+=s[i+(numRows*2-(n+1)*2)];
		}
		return tmp;
	}
};
/*
- I mistake a condition that limit check
*/