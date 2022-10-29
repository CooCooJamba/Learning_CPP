#ifndef CL_3_h
#define CL_3_h
#include "cl_2.h"
class cl_3 : public virtual cl_2 {
private:
	int value;
public:
	cl_3(int value = 0);
	int virtual get_value(int x);
};
#endif