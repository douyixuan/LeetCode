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
	ListNode* swapPairs(ListNode* head) {
		ListNode* tmp = head,*nex = NULL,*last=new ListNode(-1);
		while(tmp){
			nex=tmp->next;
			if(nex){
				tmp->next=nex->next;
				last->next=nex;
				nex->next=tmp;
				if(tmp==head) head=nex;
				last=tmp;
				tmp=tmp->next;
				//return head;
			}
			else break;
		}
		return head;
	}
};
/*
- line 21 I made a mistake
 cause nex->next == tmp;
 I let tmp = tmp, so TLE
*/