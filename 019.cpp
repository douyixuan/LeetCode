
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
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		int num = 0;
		ListNode *cur = head;
		ListNode *tmp = head;
		for(int i=0;i<n;i++){
			cur=cur->next;
		}
		if(!cur){
			return head->next;
		}
		else{
			while(cur->next){
				cur = cur->next;
				tmp = tmp->next;
			}
			tmp->next = tmp->next->next;
			return head;
		}
	}
};