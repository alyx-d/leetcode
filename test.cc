#include <bits/stdc++.h>

int main() {
	int a = 0;
	auto foo = [&a]() { std::cout << a << std::endl; };
	a = 1;
	foo();
}