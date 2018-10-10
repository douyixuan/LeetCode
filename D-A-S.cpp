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
const LL INF=-1*1e32;
const int maxn=1e5+7;
const double PI=acos(-1.0);
LL a[maxn];
LL s[maxn]={0};
LL sum[maxn]={0};
int c[maxn]={0};
int main() {
	int t=0,T;
	freopen("/Users/mengxiangyu/Downloads/A-small-attempt0.in", "r", stdin);
	cin>>T;
	int N,O;
	LL D;
	while(T--){
		t++;
		cin>>N>>O;
		cin>>D;
		LL x1,x2,A,B,C,M,L;
		cin>>x1>>x2>>A>>B>>C>>M>>L;
		//cout<<A<<' '<<B<<endl;
		sum[0]=0;
		c[0]=0;
		a[1]=x1;
		a[2]=x2;
		s[1]=a[1]+L;
		s[2]=a[2]+L;
		/*
		for(int i=3;i<=N;i++){
			a[i]=(A*a[i-1]%M+B*a[i-2]%M+C%M)%M;
			s[i]=a[i]+L;
			//cout<<s[i]<<' ';
		}*/
		//cout<<endl;
		
		for(int i=1;i<=N;i++){
			sum[i]= s[i]+sum[i-1];
			c[i]= abs(s[i])%2==1?c[i-1]+1:c[i-1];
		//	cout<<sum[i]<<' '<<c[i]<<endl;
		}
		
		LL tmp=0;
		LL ans=INF;
		int i=0,j=1;
		int num=0;
		//queue<int> que;
		/*
		while (i<=N && j<=N) {
			int num=c[j]-c[i];
			tmp=sum[j]-sum[i];
			//cout<<j<<' '<<i<<' '<<tmp<<endl;
			if(num<=O){
				if(tmp<=D){
					ans=max(ans,tmp);
					j++;
				}
				else{
					while(tmp>D && i<=j){
						
						i++;
						tmp=sum[j]-sum[i];
					}
					if(tmp>D){
						swap(i, j);
					}
				}
			}
			else{
				for(int x=i+1;x<=j;x++){
					if(abs(s[x])%2==1){
						i=x;
						break;
					}
				}
				tmp=sum[j]-sum[i];
			}
		}*/
		cout<<"Case #"<<t<<": ";
		if(ans==INF) cout<<"IMPOSSIBLE";
		else cout<<ans;
		cout<<endl;
	}
	return 0;
}