#include "cl_4.h"
#include <iostream>
cl_4::cl_4(string name) {
	this->name = name + "_4";
}
void cl_4::get_name() {
	cout << name << endl;
}