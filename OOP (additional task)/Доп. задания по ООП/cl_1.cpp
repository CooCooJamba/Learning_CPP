#include "cl_1.h"
#include <iostream>
cl_1::cl_1(string name, int value) {
	this->name = name + "_1";
	this->value = value;
}
void cl_1::get_inf() {
	cout << name << " " << value << endl;
}