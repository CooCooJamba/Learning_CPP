#ifndef CL_BASE_H
#define CL_BASE_H
#include <string>
#include <vector>
#include <iostream>
using namespace std;
class cl_base;
typedef void(cl_base::* SIGNAL) (string&);
typedef void(cl_base::* HANDLER) (string);
#define SIGNAL_D(signal) (SIGNAL) (&signal)
#define HANDLER_D(handler) (HANDLER) (&handler)
class cl_base {
private:
	cl_base* reference;
	int readiness = 1;
	int classnum;
	string name;
	struct main_object {
		SIGNAL signal;
		cl_base* ptr;
		HANDLER handler;
	};
public:
	vector<cl_base*> children;
	vector<main_object*> connections;
	vector<cl_base*>::iterator iter;
	cl_base(string name = "", cl_base* reference = nullptr, int classnum = 1);
	cl_base* get_parent(string name);
	void set_readiness(int readiness);
	int get_readiness();
	void reset_readiness(cl_base* reference = nullptr);
	void set_name(string name);
	string get_name();
	void add_child(cl_base* reference);
	void show_tree(int i = 0);
	cl_base* find(string name, cl_base* ptr, cl_base* temp = nullptr);
	void set_connect(SIGNAL signal, cl_base* to, HANDLER handler);
	void delete_connect(SIGNAL signal, cl_base* to, HANDLER handler);
	void set_condition(cl_base* ptr, int readiness);
	void emit(SIGNAL signal, string& command);
	string get_way(cl_base* ptr);
	int get_classnum();
	SIGNAL find_signal(int i);
	HANDLER find_handler(int i);
};
#endif