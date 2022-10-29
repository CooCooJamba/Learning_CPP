#include "cl_3.h"
#include <iostream>
cl_3::cl_3(string name, int value) : cl_2(name, value) {
	this->name = name + "_3";
	this->value = value * value * value;
};
void cl_3::get_inf() {
	cl_3::cl_2::get_inf();
	cout << name << " " << value << endl;
}