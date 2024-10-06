#include "define.h"

class Solution {
   public:
	int getLength(ListNode* head) {
		int length = 0;
		while (head) {
			length++;
			head = head->next;
		}
		return length;
	}
	TreeNode* buildTree(ListNode*& head, int left, int right) {
		if (left > right) {
			return nullptr;
		}
		int mid = left + (right - left) / 2;
		TreeNode* root = new TreeNode();
		root->left = buildTree(head, left, mid - 1);
		root->val = head->val;
		head = head->next;
		root->right = buildTree(head, mid + 1, right);
		return root;
	}
	TreeNode* sortedListToBST(ListNode* head) {
		return buildTree(head, 0, getLength(head) - 1);
	}
};