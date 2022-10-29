#include "cl_1.h"
#include <iostream>
cl_1::cl_1(string name) {
	this->name = name + "_1";
}
void cl_1::get_name() {
	cout << name << endl;
}