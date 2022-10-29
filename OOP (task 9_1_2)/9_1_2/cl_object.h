#ifndef __CL_OBJECT_H__
#define __CL_OBJECT_H__
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <bitset>
#include <map>
using namespace std;
class cl_object {
private:
	bitset<8> value;
	bitset<8> pattern;
public:
	cl_object(string value = "", string pattern = "");
	string get_result();
	cl_object& operator&(cl_object& obj);
	cl_object& operator|(cl_object& obj);
};
#endif