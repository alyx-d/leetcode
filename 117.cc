#include "define.h"

class Solution {
   public:
	Node* connect(Node* root) {
		auto level = vector<Node*>();
		function<void(Node*, int)> dfs = [&dfs, &level](Node* root, int depth) {
			if (!root) {
				return;
			}
			if (depth == level.size()) {
				level.push_back(root);
			} else {
				level[depth]->next = root;
				level[depth] = root;
			}
			dfs(root->left, depth + 1);
			dfs(root->right, depth + 1);
		};
		dfs(root, 0);
		return root;
	}
};