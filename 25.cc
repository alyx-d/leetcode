#include "define.h"

class Solution {
   public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		ListNode* dummy = new ListNode(0, head);
		ListNode* prev = dummy;
		while (head) {
			ListNode* tail = prev;
			for (int i = 0; i < k; i++) {
				tail = tail->next;
				if (!tail) {
					return dummy->next;
				}
			}
			ListNode* next = tail->next;
			tie(head, tail) = reverse(head, tail);
			prev->next = head;
			tail->next = next;

			prev = tail;
			head = tail->next;
		}
		return dummy->next;
	}
	pair<ListNode*, ListNode*> reverse(ListNode* head, ListNode* tail) {
		ListNode* prev = tail->next;
		ListNode* curr = head;
		while (prev != tail) {
			ListNode* next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
		}
		return {tail, head};
	}
};