#ifndef CL_4_H
#define CL_4_H
#include "cl_base.h"
class cl_4 : public cl_base {
private:
	int classnum;
public:
	cl_4(string name, cl_base* reference, int classnum) : cl_base(name, reference, classnum) {};
};
#endif