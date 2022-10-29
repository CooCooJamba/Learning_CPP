#ifndef CL_2_H
#define CL_2_H
#include "cl_base.h"
class cl_2 : public cl_base {
public:
	cl_2(string name, cl_base* reference, int classnum) : cl_base(name, reference, classnum) {};
	void signal_2(string& command);
	void handler_2(string command);
};
#endif