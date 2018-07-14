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
		// bug 0 
		if (!head || k == 1) return head;
		ListNode* start = new ListNode(-1);
		ListNode* cur = head,*pre=start;
		int i=0;
		// bug 1
		pre->next = head;
		while(cur){
			i++;
			if(i%k==0){
				// bug 2
				pre = reverse(pre,cur->next);
				// bug 3
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
			// bug 4
			pre->next = cur->next;
			// reverse operation matching the below
			cur->next = begin->next;
			// first point to thr last onebyone
			begin->next = cur;
			// move to next
			cur = pre->next;
		}
		return pre;
	}
};
/*
- special judge for no change and no pre && cur cause group number = 1
- special situation for only one group and less than k
- all reverse connection finished in fun::reverse()
- forget update the value of "cur"
- pre->next & begin->next are using for memory to save value about cur;
*/