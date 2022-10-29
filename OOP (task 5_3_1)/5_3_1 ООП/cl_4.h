#ifndef CL_4_h
#define CL_4_h
#include "cl_1.h"
#include "cl_2.h"
#include "cl_3.h"
class cl_4 : public virtual cl_3 {
private:
	int value1;
	int value2;
	int value3;
	int value4;
public:
	cl_4(int value1, int value2, int value3, int value4);
	int virtual get_value(int x);
};
#endif