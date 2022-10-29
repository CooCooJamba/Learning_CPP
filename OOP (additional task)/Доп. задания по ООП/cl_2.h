#ifndef CL_2_H
#define CL_2_H
#include <string>
#include "cl_1.h"
using namespace std;
class cl_2 : public cl_1 {
private:
	string name;
	int value;
public:
	cl_2(string name = "", int value = 0);
	void get_inf();
};
#endif