#include "define.h"

class Solution {
   public:
	Node* connect(Node* root) {
		function<void(Node*)> dfs = [&dfs](Node* root) {
			if (!root) {
				return;
			}
			dfs(root->left);
			dfs(root->right);
			Node* left = root->left;
			Node* right = root->right;
			while (left) {
				left->next = right;
				left = left->right;
				right = right->left;
			}
		};
		dfs(root);
		return root;
	}
};