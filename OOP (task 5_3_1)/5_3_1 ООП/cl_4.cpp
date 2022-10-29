#include "cl_1.h"
#include "cl_2.h"
#include "cl_3.h"
#include "cl_4.h"
cl_4::cl_4(int value1, int value2, int value3, int value4) : cl_1(value1), cl_2(value2), cl_3(value3) {
	this->value4 = value4;
}
int cl_4::get_value(int x) {
	return cl_3::get_value(x) + value4 * x * x * x * x;
}