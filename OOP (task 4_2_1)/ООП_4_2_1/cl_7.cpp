#include "cl_7.h"
#include <iostream>
cl_7::cl_7(string name) : cl_4(name), cl_5(name) {
	this->name = name + "_7";
}
void cl_7::get_name() {
	cout << name << endl;
}