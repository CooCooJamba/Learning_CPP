#ifndef CL_6_H
#define CL_6_H
#include "cl_base.h"
class cl_6 : public cl_base {
private:
	int classnum;
public:
	cl_6(string name, cl_base* reference, int classnum) : cl_base(name, reference, classnum) {};
};
#endif