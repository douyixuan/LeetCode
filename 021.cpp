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
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode *tmp = new ListNode(-1),*ans=tmp;
		while(l1&&l2){
			int a=l1->val,b=l2->val;
			if(a<b){
				tmp->next=l1;
				tmp=tmp->next;
				l1=l1->next;
			}else{
				tmp->next=l2;
				tmp=tmp->next;
				l2=l2->next;
			}
		}
		if(l1) tmp->next=l1;
		if(l2) tmp->next=l2;
		return ans->next;
	}
};
/*
- create a node using pointer:
	Node * cur = new Node(-1);
*/