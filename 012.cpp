class Solution {
public:
	string intToRoman(int num) {
		string roma[10][4]={
			"","","","",
			"I","X","C","M",
			"II","XX","CC","MM",
			"III","XXX","CCC","MMM",
			"IV","XL","CD","",
			"V","L","D","",
			"VI","LX","DC","",
			"VII","LXX","DCC","",
			"VIII","LXXX","DCCC","",
			"IX","XC","CM",""
		};
		int ans[4]={0};
		if(num) ans[0]=num%10,num/=10;
		if(num) ans[1]=num%10,num/=10;
		if(num) ans[2]=num%10,num/=10;
		if(num) ans[3]=num%10;
		return roma[ans[3]][3]+roma[ans[2]][2]+roma[ans[1]][1]+roma[ans[0]][0];
	}
};
/*
- 赋值给二维数组不能用‘；’  ？？？？

*/
