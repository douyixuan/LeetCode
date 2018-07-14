class Solution {
public:
	typedef long long ll;
	int divide(int dividend, int divisor) {
		if(divisor == 0 ) return INT_MAX;
		// bug 0
		ll m = abs((ll)dividend), n = abs((ll)divisor), sign = 1;
		// bug 1
		if((dividend<0) ^ (divisor<0)) sign = -1;
		ll ans = 0;
		// bug 2
		while(m>=n){
			ll p = 1, t = n;
			// bug 3
			while(m>(t<<1)){
				p<<=1;
				t<<=1;
			}
			m -= t;
			ans += p;
		}
		// tip 0
		if(sign == -1) ans=-ans;
		return ans>INT_MAX? INT_MAX : ans;
		
	}
};
/*
sample:
-2147483648
1
-2147483648
-1
note:
	- abs(int) = int , so it's necessary to change into ll
	- bit-calc division has to ensure two positive
	- every time find a max 2-bit number add to ans
	- yupan or just now
tip:
	- change the value, formalize the return result
*/