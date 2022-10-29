#include "cl_3.h"
#include <iostream>
cl_3::cl_3(string name) {
	this->name = name + "_3";
}
void cl_3::get_name() {
	cout << name << endl;
}