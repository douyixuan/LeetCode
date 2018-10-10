#include<iostream>
#include<stdio.h>
#include<cstdio>
#include<string>
#include<cmath>
#include<stdlib.h>
#include<algorithm>
#include<string.h>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
#include<set>
using namespace std;
 
const int maxn=22;
long long N;
int arr[maxn];
int ed;
long long ans;
int tmparr[maxn];
int T;
int higest_odd(int a[], int aed)
{
	int ret=-1;
	for(int i=0;i<aed;i++)
	{
		if(a[i]%2==1)
		{
			ret=i;
		}
	}
	return ret;
}
void print_tmparr()
{
	for(int i=ed;i>=0;i--)
	{
		cout<<tmparr[i];
	}
	cout<<endl;
}
void print_arr()
{
	for(int i=ed;i>=0;i--)
	{
		cout<<arr[i];
	}
	cout<<endl;
}
int find_tmparr_end()
{
	int ret=0;
	for(int i=ed+1;i>=0;i--)
	{
		//cout<<"i "<<i<<" tmparr[i] "<<tmparr[i]<<endl;
		if(tmparr[i]>0)
		{
			ret=i;
			break;
		}
	}
	return ret;
}
long long cal_gap(int a[])
{
	long long ret1=0;
	long long ret2=0;
	for(int i=ed-1;i>=0;i--)
	{
		ret1=ret1*10+arr[i];
	}
	int ed2=find_tmparr_end()+1;
	//cout<<"tmparr ed2 "<<ed2<<endl;
	for(int i=ed2-1;i>=0;i--)
	{
		ret2=ret2*10+a[i];
	}
	//cout<<ret1<<" ret "<<ret2<<endl;
	if(ret1>ret2)
	{
		return ret1-ret2;
	}
	else
	{
		return ret2-ret1;
	}
}
int main()
{
//    freopen("input.txt","r",stdin);
 
	//freopen("A-large.in","r",stdin);
	freopen("/Users/mengxiangyu/Downloads/A-large-practice.in", "r",stdin);
	freopen("/Users/mengxiangyu/Downloads/leetcode/LeetCode/Alarge.out.cpp","w",stdout);
	cin>>T;
	for(int ca=1;ca<=T;ca++)
	{
		memset(arr,0,sizeof(arr));
		memset(tmparr,0,sizeof(tmparr));
		ed=0;
		ans=0;
		cin>>N;
//cout<<N<<endl;
		long long tmpN=N;
		int maxed=-1;
		while(tmpN!=0)
		{
			arr[ed]=tmpN%10;
			if(arr[ed]%2==1)
			{
				maxed=ed;
			}
			tmpN=tmpN/10;
			ed++;
		}
		if(maxed==-1)
		{
			ans=0;
			printf("Case #%d: %lld\n", ca, ans);
			continue;
		}
		memset(tmparr,0,sizeof(tmparr));
		// add
		//cout<<"add"<<endl;
		for(int i=0;i<maxed;i++)
		{
			tmparr[i]=0;
		}
		tmparr[maxed]=arr[maxed];
		for(int i=maxed+1;i<ed;i++)
		{
			tmparr[i]=arr[i];
		}
		//print_tmparr();
		while(true)
		{
			maxed=higest_odd(tmparr,ed+1);
			//cout<<"maxed "<<maxed<<" tmparr "<<endl;
			//print_tmparr();
			if(maxed==-1)
			{
				break;
			}
			tmparr[maxed]=tmparr[maxed]+1;
			int idx=maxed;
			//cout<<"ed "<<ed<<" idx "<<idx<<endl;
			while(tmparr[idx]==10)
			{
				tmparr[idx]=0;
				idx++;
				tmparr[idx]=tmparr[idx]+1;//the same as using tmparr?
				//print_tmparr();
			}
 
		}
//print_tmparr();
		ans=cal_gap(tmparr);
		//sub
		//cout<<"sub"<<endl;
		memset(tmparr,0,sizeof(tmparr));
		maxed=higest_odd(arr,ed);
		tmparr[maxed]=arr[maxed]-1;
		//print_arr();
		//cout<<"maxed "<<maxed<<endl;
		//print_tmparr();
		for(int i=maxed+1;i<ed+1;i++)
		{
			tmparr[i]=arr[i];
		}
		//print_tmparr();
		for(int i=0;i<maxed;i++)
		{
			tmparr[i]=8;
		}
//print_tmparr();
		ans=min(ans,cal_gap(tmparr));
		printf("Case #%d: %lld\n", ca, ans);
 
	}
	return 0;
}
