#include <iostream>
#include "cl_4.h"
using namespace std;
int main() {
	string name;
	int value;
	cin >> name >> value;
	cl_4 c4(name, value);
	c4.get_inf();
	return 0;
}