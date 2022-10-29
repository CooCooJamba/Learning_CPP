#include "cl_1.h"
#include "cl_2.h"
#include "cl_3.h"
#include "cl_4.h"
#include "cl_5.h"
#include "cl_6.h"
#include "iomanip"
cl_base::cl_base(string name, cl_base* reference, int classnum) {
	if (name == "") { cin >> name; };
	set_name(name);
	if (reference) { this->reference = reference; };
	this->classnum = classnum;
}
cl_base* cl_base::get_parent(string name) {
	return find(name, this)->reference;
}
void cl_base::set_readiness(int readiness) {
	this->readiness = readiness;
}
int cl_base::get_readiness() {
	return readiness;
}
void cl_base::reset_readiness(cl_base* reference) {
	for (auto iter : reference->children) {
		iter->set_readiness(0);
		if (iter->children.size() != 0) { reset_readiness(iter); };
	}
}
void cl_base::add_child(cl_base* reference) {
	children.push_back(reference);
}
void cl_base::set_connect(SIGNAL signal, cl_base* to, HANDLER handler) {
	main_object* m_o;
	for (int i = 0; i < connections.size(); i++) {
		if (connections[i]->ptr == to) { return; };
	}
	m_o = new main_object();
	m_o->signal = signal;
	m_o->ptr = to;
	m_o->handler = handler;
	connections.push_back(m_o);
}
void cl_base::delete_connect(SIGNAL signal, cl_base* to, HANDLER handler) {
	for (int i = 0; i < connections.size(); i++) {
		if (connections[i]->ptr == to) { connections.erase(connections.begin() + i); return; };
	}
}
void cl_base::set_condition(cl_base* ptr, int readiness) {
	if (get_parent(ptr->get_name()) == nullptr) { this->set_readiness(readiness); return; };
	if (get_parent(ptr->get_name()) != nullptr && get_parent(ptr->get_name())->readiness != 0) { ptr->set_readiness(readiness); };
	if (ptr->children.size() != 0 && ptr->get_readiness() == 0) { reset_readiness(ptr); return; };
}
void cl_base::emit(SIGNAL signal, string& command) {
	HANDLER handler;
	(this->*signal)(command);
	if (connections.empty()) return;
	for (auto iter : connections) {
		if (iter->ptr->get_readiness() != 0) {
			if (iter->signal == signal) {
				handler = iter->handler;
				(iter->ptr->*handler)(command);
			}
		}
	}
}
string cl_base::get_way(cl_base* ptr) {
	if (ptr->reference != nullptr) { return get_way(ptr->reference) + '/' + ptr->get_name(); };
	return "";
}
int cl_base::get_classnum() {
	return this->classnum;
}
void cl_base::set_name(string name) {
	this->name = name;
}
string cl_base::get_name() {
	return name;
}
void cl_base::show_tree(int i) {
	i++;
	for (iter = this->children.begin(); iter < this->children.end(); iter++) {
		cout << "\n" << setw(4 * i + (*iter)->get_name().length()) << (*iter)->get_name();
		if ((*iter)->children.size() != 0) { (*iter)->show_tree(i); };
	}
}
cl_base* cl_base::find(string name, cl_base* ptr, cl_base* temp) {
	if (name == ptr->get_name()) { return ptr; };
	for (iter = ptr->children.begin(); iter < ptr->children.end(); iter++) {
		temp = (*iter)->find(name, *iter);
		if (temp == nullptr) { continue; };
		if (name == temp->get_name()) { return temp; };
	}
	return nullptr;
}
SIGNAL cl_base::find_signal(int i) {
	switch (i) {
	case 1: return SIGNAL_D(cl_1::signal_1);
	case 2: return SIGNAL_D(cl_2::signal_2);
	case 3: return SIGNAL_D(cl_3::signal_3);
	case 4: return SIGNAL_D(cl_4::signal_4);
	case 5: return SIGNAL_D(cl_5::signal_5);
	case 6: return SIGNAL_D(cl_6::signal_6);
	}
	return nullptr;
}
HANDLER cl_base::find_handler(int i) {
	switch (i) {
	case 1: return HANDLER_D(cl_1::handler_1);
	case 2: return HANDLER_D(cl_2::handler_2);
	case 3: return HANDLER_D(cl_3::handler_3);
	case 4: return HANDLER_D(cl_4::handler_4);
	case 5: return HANDLER_D(cl_5::handler_5);
	case 6: return HANDLER_D(cl_6::handler_6);
	}
	return nullptr;
}