#ifndef CL_1_H
#define CL_1_H
#include <string>
using namespace std;
class cl_1 {
private:
	string name;
	int value;
public:
	cl_1(string name = "", int value = 0);
	void get_inf();
};
#endif