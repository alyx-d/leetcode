#include "define.h"

class Solution {
   public:
	ListNode* deleteDuplicates(ListNode* head) {
		ListNode* dummy = new ListNode(0, head);
		ListNode* curr = dummy;
		while (curr && curr->next && curr->next->next) {
			if (curr->next->val != curr->next->next->val) {
				curr = curr->next;
			} else {
				int val = curr->next->val;
				while (curr && curr->next && val == curr->next->val) {
					curr->next = curr->next->next;
				}
			}
		}
		return dummy->next;
	}
};