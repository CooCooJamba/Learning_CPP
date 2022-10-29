#ifndef CL_2_h
#define CL_2_h
#include "cl_1.h"
class cl_2 : public virtual cl_1 {
private:
	int value;
public:
	cl_2(int value = 0);
	int virtual get_value(int x);
};
#endif