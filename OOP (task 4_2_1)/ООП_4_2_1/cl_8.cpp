#include "cl_8.h"
#include <iostream>
cl_8::cl_8(string name) : cl_6(name), cl_7(name), cl_1(name) {
	this->name = name + "_8";
}
void cl_8::get_name() {
	cout << name;
}