#include <iostream>
#include "cl_1.h"
#include "cl_2.h"
#include "cl_3.h"
#include "cl_4.h"
using namespace std;
int main() {
	int a1, a2, a3, a4, x, class_num;
	cin >> a1 >> a2 >> a3 >> a4;
	cl_4 c4(a1, a2, a3, a4);
	cout << "a1 = " << a1 << "    a2 = " << a2 << "    a3 = " << a3 << "    a4 = " << a4 << endl;
	while (true) {
		cin >> x;
		if (x == 0) {
			break;
		}
		cin >> class_num;
		switch (class_num) {
			case 1: cout << "Class " << class_num << "    F(" << x << ") = " << ((cl_1)c4).get_value(x); break;
			case 2: cout << "Class " << class_num << "    F(" << x << ") = " << ((cl_2)c4).get_value(x); break;
			case 3: cout << "Class " << class_num << "    F(" << x << ") = " << ((cl_3)c4).get_value(x); break;
			case 4: cout << "Class " << class_num << "    F(" << x << ") = " << ((cl_4)c4).get_value(x); break;
			default: break;
		}
		cout << endl;
	}
	return 0;
}