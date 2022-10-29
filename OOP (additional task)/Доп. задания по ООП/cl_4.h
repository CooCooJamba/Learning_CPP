#ifndef CL_4_H
#define CL_4_H
#include <string>
#include "cl_3.h"
using namespace std;
class cl_4 : public cl_3 {
private:
	string name;
	int value;
public:
	cl_4(string name = "", int value = 0);
	void get_inf();
};
#endif