#include "define.h"

class Solution {
   public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		return mergeKLists(lists, 0, lists.size() - 1);
	}

	ListNode* mergeKLists(vector<ListNode*>& lists, int left, int right) {
		if (left > right) {
			return nullptr;
		}
		if (left == right) {
			return lists[left];
		}
		int mid = left + (right - left) / 2;
		return mergeTwo(mergeKLists(lists, left, mid),
						mergeKLists(lists, mid + 1, right));
	}

	ListNode* mergeTwo(ListNode* l1, ListNode* l2) {
		ListNode* dummy = new ListNode();
		ListNode* curr = dummy;
		while (l1 && l2) {
			ListNode* node = new ListNode();
			if (l1->val < l2->val) {
				node->val = l1->val;
				l1 = l1->next;
			} else {
				node->val = l2->val;
				l2 = l2->next;
			}
			curr->next = node;
			curr = curr->next;
		}
		curr->next = l1 ? l1 : l2;
		return dummy->next;
	}
};