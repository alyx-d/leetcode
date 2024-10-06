#include "define.h"

class Solution {
   public:
	ListNode* rotateRight(ListNode* head, int k) {
		if (k == 0 || !head || !head->next) {
			return head;
		}
		int n = 1;
		ListNode* curr = head;
		while (curr->next) {
			n++;
			curr = curr->next;
		}
		int count = n - k % n;
		if (count == n) {
			return head;
		}
		curr->next = head;
		while (count--) {
			curr = curr->next;
		}
		ListNode* ans = curr->next;
		curr->next = nullptr;
		return ans;
	}
};