#ifndef CL_3_H
#define CL_3_H
#include <string>
#include "cl_2.h"
using namespace std;
class cl_3 : public cl_2 {
private:
	string name;
	int value;
public:
	cl_3(string name = "", int value = 0);
	void get_inf();
};
#endif