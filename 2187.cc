#include <bits/stdc++.h>

class Solution {
   public:
	long long minumumTime(std::vector<int> &time, int totalTrips) {
		long long count = 0;
		const int n = time.size();
		long long l = 1;
		long long r =
			*std::min_element(time.begin(), time.end()) * (long long)totalTrips;
		while (l < r) {
			long long mid = l + ((r - l) >> 1);
			for (int i = 0; i < n; i++) {
				count += mid / time[i];
			}
			if (count >= totalTrips) {
				r = mid;
			} else {
				l = mid + 1;
			}
			count = 0;
		}
		return l;
	}
};

int main() { std::cout << "2187 src file" << std::endl; }