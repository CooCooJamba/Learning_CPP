#include "cl_2.h"
#include <iostream>
cl_2::cl_2(string name) {
	this->name = name + "_2";
}
void cl_2::get_name() {
	cout << name << endl;
}