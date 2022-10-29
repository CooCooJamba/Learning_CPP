#include "cl_3.h"
cl_3::cl_3(int value) {
	this->value = value;
}
int cl_3::get_value(int x) {
	return cl_2::get_value(x) + value * x * x * x;
}