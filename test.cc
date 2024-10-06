#include <bits/stdc++.h>
using namespace std;

std::vector<int> a = {1};
void f(std::vector<int>& a) { a = {2, 3}; }

void printVec(std::vector<int>& a) {
	cout << "std::vector[";
	string seq = "";
	for (auto it : a) {
		cout << seq << it;
		seq = ",";
	}
	cout << "]" << endl;
}
int main() {
	printVec(a);
	f(a);
	printVec(a);
}