/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		if(lists.size()==0) return NULL;
		int n=lists.size();
		while(n>1){//分治 is so hard
			int k=(n+1)/2;
			for(int i=0;i<n/2;i++){
				lists[i]=mergeTwo(lists[i],lists[i+k]);
			}
			n=k;
		}
		return lists[0];
	}
	ListNode* mergeTwo(ListNode*a, ListNode * b){
		ListNode* tmp = new ListNode(-1),*ans=tmp;
		while(a&&b){
			if(a->val<b->val){
				tmp->next=a;
				tmp=tmp->next;
				a=a->next;
			}
			else{
				tmp->next=b;
				tmp=tmp->next;
				b=b->next;
			}
			
		}
		if(a) tmp->next=a;
		else tmp->next=b;
		return ans->next;
	}
};
/*
- about divide into two parts;
first combine two but thw two are not supposed to be adjacent
then base on the decrease ceil combine two

- priority_queue<Type, Container, Functional>
Type为数据类型， Container为保存数据的容器，Functional为元素比较方式。
如果不写后两个参数，那么容器默认用的是vector，比较方式默认用operator<，也就是优先队列是大顶堆，队头元素最大。
struct cmp {
	bool operator () (ListNode *a, ListNode *b) {
		return a->val > b->val;
	}
};// from small to large 
priority_queue<ListNode*, vector<ListNode*>, cmp> q;
*/