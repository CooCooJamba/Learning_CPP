#ifndef CL_3_H
#define CL_3_H
#include "cl_base.h"
class cl_3 : public cl_base {
private:
	int classnum;
public:
	cl_3(string name, cl_base* reference, int classnum) : cl_base(name, reference, classnum) {};
};
#endif