#include "cl_2.h"
#include <iostream>
cl_2::cl_2(string name, int value) : cl_1(name, value) {
	this->name = name + "_2";
	this->value = value * value;
};
void cl_2::get_inf() {
	cl_2::cl_1::get_inf();
	cout << name << " " << value << endl;
}