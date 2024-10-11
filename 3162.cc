#include "define.h"

class Solution {
   public:
	int numOfPairs(vector<int> &nums1, vector<int> &nums2, int k) {
		const int m = nums1.size();
		const int n = nums2.size();
		int ans = 0;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (nums1[i] % nums2[j] * k == 0) {
					ans++;
				}
			}
		}
		return ans;
	}
};