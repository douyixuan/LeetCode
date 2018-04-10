class Solution {
public:
	int reverse(int x) {
		long long ans=0;
		int b=0;//,flag=1;
		//if(x<0) flag=-1;
		while(x){
			if(b==0 && x%10!=0)
				b=1;
			if(b) ans=ans*10+x%10;
			x/=10;
		}
		if(ans>=(1<<31)-1) ans=0;
		if(ans<=(-1<<31)+1) ans=0;
		return ans;
	}
};
/*
- signed 32-bit integer :   -1<<31  ~  1<<31-1   
   
	INT_MAX (2147483647) ~ INT_MIN (-2147483648) 

- (-1<<31)-1 = 2147483647

-   -1 = 1<<32-1

- flag has no effect
*/