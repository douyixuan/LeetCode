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
	ListNode* reverseKGroup(ListNode* head, int k) {
		if (!head || k == 1) return head;
		ListNode* start = new ListNode(-1);
		ListNode* cur = head,*pre=start;
		int i=0;
		pre->next = head;
		while(cur){
			i++;
			if(i%k==0){
				pre = reverse(pre,cur->next);
				cur = pre->next;
			}
			else{
				cur = cur->next;
			}
		}
		return start->next;
	}
	ListNode* reverse(ListNode* begin, ListNode* end){
		ListNode* pre=begin->next;
		ListNode* cur=pre->next;
		while(cur!=end){
			pre->next = cur->next;
			cur->next = begin->next;
			begin->next = cur;
			cur = pre->next;
		}
		return pre;
	}
};