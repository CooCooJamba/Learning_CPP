#include <iostream>
#include "cl_8.h"
using namespace std;
int main() {
	cl_8* cptr8;
	string name;
	cin >> name;
	cl_8 c8(name);
	cptr8 = &c8;
	((cl_1)(*cptr8)).get_name();
	((cl_1)(*cptr8)).get_name();
	((cl_1)(*cptr8)).get_name();
	((cl_2)(*cptr8)).get_name();
	((cl_3)(*cptr8)).get_name();
	((cl_4)(*cptr8)).get_name();
	((cl_5)(*cptr8)).get_name();
	((cl_6)(*cptr8)).get_name();
	((cl_7)(*cptr8)).get_name();
	((cl_8)(*cptr8)).get_name();
	return 0;
}