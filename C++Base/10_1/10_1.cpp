#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> v1 = { 12, 321, 41, 1 };
	vector<int>::iterator ite = v1.begin();
	while (ite != v1.end()) {
		cout << *ite++ << " ";
		ite++;
	}
	cout << endl;
	return 0;
}
