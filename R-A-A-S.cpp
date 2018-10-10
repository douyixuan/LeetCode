#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cassert>
#include <queue>
#include <deque>
#include <cstdlib>
#include <set>
#include <map>
#define PB push_back
#define MP make_pair

using namespace std;
typedef pair<int,int> PII;
typedef long long LL;
const int MOD=1e9+7;
const int maxn=1e5+7;
const double PI=acos(-1.0);
string convert2s(LL a){
	string s="";
	while(a){
		char ch = '0'+a%10;
		s+=ch;
		a/=10;
	}
	//reverse(s.begin(),s.end());
	return s;
}
int main() {
	freopen("/Users/mengxiangyu/Downloads/A-large-practice.in", "r",stdin);
	int t=0,T;
	cin>>T;
	LL a;
	while(T--){
		t++;
		cin>>a;
		string s=convert2s(a);
		cout<<a<<endl<<s<<endl;
		int bor=0;
		LL ten = 1;
		LL ans=0;
		for(int i=0;i<s.size();i++){
			if(s[i]&1){
				if(s[i]>bor){
					s[i]=s[i]-bor-1;
					bor=0;
					ans+=ten;
				}
				else{
					s[i]=s[i]+10-bor-1;
					bor=1;
					ans+=ten;
				}
			}
			ten*=10;
		}
		reverse(s.begin(),s.end());
		for(int i=0;i<s.size()&&s[i]=='0';) s=s.substr(i+1);
		printf("Case #%d: ",t);
		cout<<s<<endl;
	}
	return 0;
}
/*

++

--

最高位的处理

比较

*/