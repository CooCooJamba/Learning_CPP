#ifndef CL_3_H
#define CL_3_H
#include "cl_1.h"
#include <string>
using namespace std;
class cl_3 : virtual public cl_1 {
private:
	string name;
public:
	cl_3(string name = "");
	void get_name();
};
#endif