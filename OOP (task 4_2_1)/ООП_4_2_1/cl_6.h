#ifndef CL_6_H
#define CL_6_H
#include "cl_2.h"
#include "cl_3.h"
#include <string>
using namespace std;
class cl_6 : public cl_2, public cl_3 {
private:
	string name;
public:
	cl_6(string name = "");
	void get_name();
};
#endif