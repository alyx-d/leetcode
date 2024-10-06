#include "define.h"

class Solution {
   public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode* dummy = new ListNode();
		dummy->next = head;
		ListNode* prev = dummy;
		ListNode* curr = head;
		for (int i = 0; i < n; i++) {
			curr = curr->next;
		}
		while (curr) {
			prev = prev->next;
			curr = curr->next;
		}
		prev->next = prev->next->next;
		return dummy->next;
	}
};