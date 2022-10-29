#ifndef CL_8_H
#define CL_8_H
#include "cl_6.h"
#include "cl_7.h"
#include <string>
using namespace std;
class cl_8 : public cl_6, public cl_7 {
private:
	string name;
public:
	cl_8(string name = "");
	void get_name();
};
#endif