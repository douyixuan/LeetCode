class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		map<string,int> index;
		vector<int> ans;
		if(s.size()==0 || words.empty()) return ans;
		int n, w=words.size();
		int m = s.size();
		//if(words.size()>0) 
			n = words[0].size();
		for(int i=0; i<words.size(); i++){
			index[words[i]]++;
		}
		for(int i=0; i<m && (m-i)>=n*w; i++){
			map<string,int> cur;
            int j;
			for(j=0; j<w; ++j){
				string tmp = s.substr(i+j*n,n);
				if(index.find(tmp)==index.end()) break;
				cur[tmp]++;
				if(cur[tmp]>index[tmp]) break;
			}
		    if(j==w) ans.push_back(i);
		}
		return ans;
	}
};
/*
- special judge is needed;
- if + break  is a good choice
- decrease the name of variable to be clear
*/