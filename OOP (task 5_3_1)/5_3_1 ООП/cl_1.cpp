#include "cl_1.h"
cl_1::cl_1(int value) {
	this->value = value;
}
int cl_1::get_value(int x) {
	return value * x;
}