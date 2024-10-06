#include "define.h"

class Solution {
   public:
	ListNode* partition(ListNode* head, int x) {
		ListNode* smallVHead = new ListNode(0);
		ListNode* largeVHead = new ListNode(0);
		ListNode* small = smallVHead;
		ListNode* large = largeVHead;
		while (head) {
			if (head->val < x) {
				small->next = head;
				small = small->next;
			} else {
				large->next = head;
				large = large->next;
			}
			head = head->next;
		}
		large->next = nullptr;
		small->next = largeVHead->next;
		return smallVHead->next;
	}
};