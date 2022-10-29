#include "cl_4.h"
#include <iostream>
cl_4::cl_4(string name, int value) : cl_3(name, value) {
	this->name = name + "_4";
	this->value = value * value * value * value;
};
void cl_4::get_inf() {
	cl_4::cl_3::get_inf();
	cout << name << " " << value;
}