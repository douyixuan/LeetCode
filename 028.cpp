class Solution {
public:
	int strStr(string haystack, string needle) {
		int m = haystack.size();
		int n = needle.size();
		int ans = -1;
		for(int i=0; i<m; i++){
			if(needle[0]==haystack[i]){
				int cnt = 0;
				for(int j=0;j<n;j++){
					if(i+j<m && needle[j] == haystack[i+j]){
						cnt++;
					}
				}
				if(cnt == n){
					ans = i;
					// bug 0
					break;
				}
			}
		}
		// bug 1
		if(needle == "") ans=0;
		return ans;
	}
};
/*
- first occurance, so just leave the loop
- I ignore /the empty string/ situation, it can't be tolerant.
*/