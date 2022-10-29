#ifndef CL_5_H
#define CL_5_H
#include "cl_base.h"
class cl_5 : public cl_base {
private:
	int classnum;
public:
	cl_5(string name, cl_base* reference, int classnum) : cl_base(name, reference, classnum) {};
};
#endif