#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
	int canompleteCirCuit(vector<int> &gas, vector<int> &cost) {
		const int n = gas.size();
		int i = 0;
		while (i < n) {
			int count = 0;
			int sumGas = 0;
			int sumCost = 0;
			while (count < n) {
				int j = (count + i) % n;
				sumGas += gas[j];
				sumCost += cost[j];
				if (sumCost > sumGas) {
					break;
				}
				count++;
			}
			if (count == n) {
				return i;
			} else {
				i = i + count + 1;
			}
		}
		return -1;
	}
};