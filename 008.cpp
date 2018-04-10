class Solution {
public:
	int myAtoi(string str) {
		//remove whitespace
		int i=0;
		while(str[i]==' '&&i<str.size()){i++;}
		//find first char
		
		//not valid integral ; empty ; all whiltespace; return 0
		int flag = 1;long long ans = 0;
		if(i<str.size() && (str[i]=='-'||str[i]=='+')){
			if(str[i]=='-') flag=-1;
			i++;
		}
		if(str[i]<'0'||str[i]>'9' || i==str.size()) return 0;        
		//count the number
		while(i<str.size() && str[i]>='0' && str[i]<='9'){
			ans = ans*10+str[i]-'0';
			if(flag==1 && ans >  2147483647) {ans = 2147483647; break;}
			if(flag==-1 && ans >  2147483648) {ans = 2147483648; break;}
			i++;
		}
		//check limit
		ans*=flag;
		return ans;
	}
};

/*
check the limit I made a mistake
- cause there is sign, ans is positive
- I put the check at the wrong place
- cause long long is still not enough
- the check must be put in the while loop

*/