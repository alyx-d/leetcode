#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
	int minRefuelStops(int target, int startFuel,
					   vector<vector<int>>& stations) {
		const int n = stations.size();
		auto dp = vector<int64_t>(n + 1, 0);
		dp[0] = startFuel;
		for (int i = 0; i < n; i++) {
			for (int j = i; j >= 0; j--) {
				if (dp[j] >= stations[i][0]) {
					dp[j + 1] = max(dp[j + 1], dp[j] + stations[i][1]);
				}
			}
		}
		for (int i = 0; i <= n; i++) {
			if (dp[i] >= target) {
				return i;
			}
		}
		return -1;
	}
};