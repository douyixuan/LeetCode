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

using namespace std;
typedef pair<int,int> PII;
typedef long long LL;
const int MOD=1e9+7;
const int maxn=1e5+7;
const double PI=acos(-1.0);
double fun( double a, int b ) 
{
	double r = 1;
	double base = a;
	while( b != 0 ) 
	{
		if(b & 1)//判断奇偶性
		{
			r *= base;

		}
		base *= base; //注意：a^{2^7}=a^{2^6} * a^{2^6} ，而不是 a^{2^7}=a^{2^6} * a ，所以这是对的。
		b /= 2;//与b=b>>1相同
	}
	return r;
}
long long int fun2( int a, int b ) 
{
	long long int r = 1;
	int base = a;
	while( b != 0 ) 
	{
		if(b & 1)//判断奇偶性
		{
			r *= base;

		}
		 base *= base; //注意：a^{2^7}=a^{2^6} * a^{2^6} ，而不是 a^{2^7}=a^{2^6} * a ，所以这是对的。
		b /= 2;//与b=b>>1相同
	}
	return r;
}
int main() {
	cout<<fun(1.333333333,500)<<endl;
	return 0;
}