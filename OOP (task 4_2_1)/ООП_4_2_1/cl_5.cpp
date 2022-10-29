#include "cl_5.h"
#include <iostream>
cl_5::cl_5(string name) {
	this->name = name + "_5";
}
void cl_5::get_name() {
	cout << name << endl;
}