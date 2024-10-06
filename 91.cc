#include "define.h"

class Solution {
   public:
	ListNode* reverseBetween(ListNode* head, int left, int right) {
		if (!head || left == right) {
			return head;
		}
		ListNode* vHead = new ListNode(0, head);
		ListNode* prev = vHead;
		for (int i = 0; i < left - 1; i++) {
			prev = prev->next;
		}
		ListNode* curr = prev->next;
		for (int i = 0; i < right - left; i++) {
			ListNode* next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
		}
		return vHead->next;
	}
};