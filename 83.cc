#include "define.h"

class Solution {
   public:
	ListNode* deleteDuplicates(ListNode* head) {
		ListNode* curr = head;
		while (curr && curr->next) {
			if (curr->val != curr->next->val) {
				curr = curr->next;
			} else {
				while (curr->next && curr->val == curr->next->val) {
					curr->next = curr->next->next;
				}
			}
		}
		return head;
	}
};