#ifndef CL_1_H
#define CL_1_H
#include "cl_base.h"
class cl_1 : public cl_base {
public:
	cl_1(string name, cl_base* reference) : cl_base(name, reference) {};
	void signal_1(string& command);
	void handler_1(string command);
};
#endif