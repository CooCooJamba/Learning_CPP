#ifndef CL_7_H
#define CL_7_H
#include "cl_4.h"
#include "cl_5.h"
#include <string>
using namespace std;
class cl_7 : public cl_4, public cl_5 {
private:
	string name;
public:
	cl_7(string name = "");
	void get_name();
};
#endif