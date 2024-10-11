#include <bits/stdc++.h>
using namespace std;

class Sort {
   public:
	int partition(vector<int>& vec, int p, int q) {
		int pivot = vec[q];
		int i = p - 1;
		for (int j = p; j <= q - 1; j++) {
			if (vec[j] < pivot) {
				i++;
				swap(vec[i], vec[j]);
			}
		}
		swap(vec[i + 1], vec[q]);
		return i + 1;
	}

	void quickSort(vector<int>& vec, int p, int q) {
		if (p > q) {
			return;
		}
		int pi = partition(vec, p, q);
		quickSort(vec, p, pi - 1);
		quickSort(vec, pi + 1, q);
	}

	void siftDown(vector<int>& vec, int p, int q) {
		int parent = p;
		int child = parent * 2 + 1;
		while (child <= q) {
			if (child + 1 <= q && vec[child] < vec[child + 1]) {
				child++;
			}
			if (vec[parent] >= vec[child]) {
				return;
			} else {
				swap(vec[parent], vec[child]);
				parent = child;
				child = parent * 2 + 1;
			}
		}
	}

	void heapSort(vector<int>& vec) {
		const int n = vec.size();
		for (int i = n / 2 - 1; i >= 0; i--) {
			siftDown(vec, i, n - 1);
		}
		for (int i = n - 1; i > 0; i--) {
			swap(vec[0], vec[i]);
			siftDown(vec, 0, i - 1);
		}
	}
};

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
	Sort sort;
	vector<int> b = {5, 3, 4, 3, 2, 1};
	printVec(b);
	sort.heapSort(b);
	printVec(b);
}