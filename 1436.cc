#include "define.h"

class Solution {
   public:
	string destCity(vector<vector<string>>& paths) {
		auto dict = unordered_set<string>();
		for (auto& path : paths) {
			dict.emplace(path[0]);
		}
		for (auto& path : paths) {
			if (!dict.contains(path[1])) {
				return path[1];
			}
		}
		return "";
	}
};