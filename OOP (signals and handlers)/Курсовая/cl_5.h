#ifndef CL_5_H
#define CL_5_H
#include "cl_base.h"
class cl_5 : public cl_base {
public:
	cl_5(string name, cl_base* reference, int classnum) : cl_base(name, reference, classnum) {};
	void signal_5(string& command);
	void handler_5(string command);
};
#endif