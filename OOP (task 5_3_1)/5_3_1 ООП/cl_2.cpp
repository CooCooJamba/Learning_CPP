#include "cl_2.h"
cl_2::cl_2(int value) {
	this->value = value;
}
int cl_2::get_value(int x) {
	return cl_1::get_value(x) + value * x * x;
}