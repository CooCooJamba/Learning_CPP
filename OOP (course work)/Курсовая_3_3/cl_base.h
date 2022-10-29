#ifndef CL_BASE_H
#define CL_BASE_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class cl_base {
private:
	cl_base* reference;
	int readiness = 0;
	int classnum;
	string name;
public:
	vector<cl_base*> children;
	vector<cl_base*> connections;
	vector<cl_base*>::iterator iter;
	cl_base(string name = "", cl_base* reference = nullptr, int classnum = 1);
	void set_parent(cl_base* reference);
	cl_base* get_parent(string name);
	void set_readiness(int readiness);
	int get_readiness();
	void reset_readiness(cl_base* reference = nullptr);
	void set_name(string name);
	string get_name();
	void add_child(cl_base* reference);
	void add_connection(cl_base* reference);
	void show_tree(int i = 0);
	void show_tree_readiness(int i = 0);
	cl_base* find(string name, cl_base* ptr, cl_base* temp = nullptr);
	void set_connect(cl_base* from, cl_base* to);
	void delete_connect(cl_base* from, cl_base* to);
	void set_condition(cl_base* ptr, int readiness);
	string emit(cl_base* ptr, string text, string result);
	string get_way(cl_base* ptr);
};
#endif
//typedef void (cl_base::*SIGNAL)(string&); возврат указателя на функцию