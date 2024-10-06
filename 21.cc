#include "define.h"

class Solution {
   public:
	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
		ListNode* dummy = new ListNode();
		ListNode* curr = dummy;
		while (list1 && list2) {
			ListNode* node = new ListNode();
			if (list1->val < list2->val) {
				node->val = list1->val;
				list1 = list1->next;
			} else {
				node->val = list2->val;
				list2 = list2->next;
			}
			curr->next = node;
			curr = curr->next;
		}
		curr->next = list1 ? list1 : list2;
		return dummy->next;
	}
};