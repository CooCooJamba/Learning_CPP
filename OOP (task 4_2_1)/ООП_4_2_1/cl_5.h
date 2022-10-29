#ifndef CL_5_H
#define CL_5_H
#include "cl_1.h"
#include <string>
using namespace std;
class cl_5 : virtual public cl_1 {
private:
	string name;
public:
	cl_5(string name = "");
	void get_name();
};
#endif