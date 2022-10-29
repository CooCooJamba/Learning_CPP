#ifndef APPLICATION_H
#define APPLICATION_H
#include "cl_1.h"
#include "cl_2.h"
#include "cl_3.h"
#include "cl_4.h"
#include "cl_5.h"
#include "cl_6.h"
class application : public cl_base {
public:
	application();
	cl_base* way(string name, cl_base* obj_temp = nullptr);
	void build_tree();
	string commands();
	void set_connections();
	int exec_app();
};
#endif