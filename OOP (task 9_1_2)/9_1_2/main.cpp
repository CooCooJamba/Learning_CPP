#include <iostream>
#include "cl_object.h"
using namespace std;
int main() {
	int n;
	string value, pattern;
	cin >> n;
	vector<cl_object> vec;
	throw(1);
	for (size_t i = 0; i < n; i++) {
		cin >> value >> pattern;
		vec.push_back(cl_object(value, pattern));
	}
	int num1, num2, num1_1;
	char oper;
	while (true) {
		cin >> num1;
		if (num1 == -1) {
			break;
		}
		else {
			num1_1 = num1;
		}
		cin >> oper >> num2;
		switch (oper) {
		case '&': vec[num1_1 - 1] = vec[num1_1 - 1] & vec[num2 - 1]; break;
		case '|': vec[num1_1 - 1] = vec[num1_1 - 1] | vec[num2 - 1]; break;
		default: break;
		}
	}
	cout << vec[num1_1 - 1].get_result() << endl;
	return 0;
}