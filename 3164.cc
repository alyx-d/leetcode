#include "define.h"

class Solution {
   public:
	long long numOfPairs(vector<int> &nums1, vector<int> &nums2, int k) {
		auto dict = unordered_map<int, int>();
		const int m = nums1.size();
		const int n = nums2.size();
		for (int i = 0; i < m; i++) {
			if (nums1[i] % k) {
				continue;
			}
			const int x = nums1[i] / k;
			for (int d = 1; d < sqrt(x); d++) {
				if (x % d) {
					continue;
				}
				dict[d]++;
				if (d * d < x) {
					dict[x / d]++;
				}
			}
		}
		long long ans = 0;
		for (int i = 0; i < n; i++) {
			if (dict.contains(nums2[i])) {
				ans += dict[nums2[i]];
			}
		}
		return ans;
	}

	long long numOfPairs2(vector<int> &nums1, vector<int> &nums2, int k) {
		unordered_map<int, int> dict1, dict2;
		const int m = nums1.size();
		const int n = nums2.size();
		for (int x : nums1) {
			if (x % k == 0) {
				dict1[x / k]++;
			}
		}
		if (dict1.empty()) {
			return 0;
		}
		for (int x : nums2) {
			dict2[x]++;
		}
		const int u = max_element(dict1.begin(), dict1.end())->first;
		long long ans = 0;
		for (auto &[x, cnt] : dict2) {
			long long s = 0;
			for (int y = x; y <= u; y += x) {
				s += dict1[y];
			}
			ans += s * cnt;
		}
		return ans;
	}
};