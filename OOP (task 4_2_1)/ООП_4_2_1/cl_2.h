#ifndef CL_2_H
#define CL_2_H
#include "cl_1.h"
#include <string>
using namespace std;
class cl_2 : virtual public cl_1 {
private:
	string name;
public:
	cl_2(string name = "");
	void get_name();
};
#endif