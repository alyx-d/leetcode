#include "define.h"

class Solution {
   public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* dummy = new ListNode();
		int carry = 0;
		ListNode* curr = dummy;
		while (l1 || l2 || carry) {
			int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
			curr->next = new ListNode(sum % 10);
			carry = sum / 10;
			if (l1) {
				l1 = l1->next;
			}
			if (l2) {
				l2 = l2->next;
			}
			curr = curr->next;
		}
		return dummy->next;
	}
};