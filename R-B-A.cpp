#include <iostream>
#include <cstdio>
#include <cstring>
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
#define ms(x, y) memset(x, y, sizeof(x))

using namespace std;
typedef pair<int,int> PII;
typedef long long LL;
const int MOD=1e9+7;
const int maxn=1e5+7;
const double PI=acos(-1.0);
LL dp[10][2][22];
int num[22];
LL dfs(int pos,int sum,int has,int flag){
	if(pos==-1){
		return (sum%9!=0 && has!=0)? 1:0;
	}
	if(flag==0 && dp[sum][has][pos]!=-1){
		return dp[sum][has][pos];
	}
	LL ans=0;
	int nsum,nhas,nflag;
	int end = flag? num[pos]:9;
	for(int i=0;i<=end;i++){
		nsum = (sum+i) % 9;
		nhas = has || (i==9);
		nflag = flag && (i==end);
		ans += dfs(pos-1, nsum, nhas, nflag);
	}
	if(!flag){
		dp[sum][has][pos]=ans;
	}
}
LL solve(LL n){
	memset(num, 0, sizeof(num));
	memset(dp, -1, sizeof(dp));
	int pos=0;
	while(n){
		num[pos]=n%10;
		n/=10;
		pos++;
	}
	return dfs(pos-1,0,0,true);
}
int main() {
	int t=1,T;
	foreopen("","r",stdin);
	foreopen("Alarge.out","w",stdout);
	cin>>T;
	LL ans=0;
	LL m,n;
	while(T--){
		cin>>m>>n;
		LL res1 = solve(m-1);
		LL res2 = solve(n);
		printf("Case #%d: %lld",t++,res2-res1);
	}
	return 0;
}