#ifndef CL_4_H
#define CL_4_H
#include "cl_1.h"
#include <string>
using namespace std;
class cl_4 : virtual public cl_1 {
private:
	string name;
public:
	cl_4(string name = "");
	void get_name();
};
#endif