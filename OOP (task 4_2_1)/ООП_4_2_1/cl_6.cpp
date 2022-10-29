#include "cl_6.h"
#include <iostream>
cl_6::cl_6(string name) : cl_2(name), cl_3(name) {
	this->name = name + "_6";
}
void cl_6::get_name() {
	cout << name << endl;
}