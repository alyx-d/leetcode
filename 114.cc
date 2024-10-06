#include "define.h"

class Solution {
   public:
	void flatten(TreeNode* root) {
		if (!root) {
			return;
		}
		flatten(root->right);
		flatten(root->left);
		root->left = nullptr;
		root->right = prev;
		prev = root;
	}

   private:
	TreeNode* prev;
};