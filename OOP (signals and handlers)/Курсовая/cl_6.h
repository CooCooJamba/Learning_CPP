#ifndef CL_6_H
#define CL_6_H
#include "cl_base.h"
class cl_6 : public cl_base {
public:
	cl_6(string name, cl_base* reference, int classnum) : cl_base(name, reference, classnum) {};
	void signal_6(string& command);
	void handler_6(string command);
};
#endif