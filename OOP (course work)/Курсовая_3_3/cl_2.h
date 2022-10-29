#ifndef CL_2_H
#define CL_2_H
#include "cl_base.h"
class cl_2 : public cl_base {
private:
	int classnum;
public:
	cl_2(string name, cl_base* reference, int classnum) : cl_base(name, reference, classnum) {};
};
#endif