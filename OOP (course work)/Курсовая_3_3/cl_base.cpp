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
void cl_base::set_parent(cl_base* reference) {
	if (reference) { this->reference = reference; };
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
void cl_base::add_connection(cl_base* reference) {
	connections.push_back(reference);
}
void cl_base::set_connect(cl_base* from, cl_base* to) {
	for (iter = from->connections.begin(); iter < from->connections.end(); iter++) {
		if (*iter == to) {
			return;
		}
	}
	from->add_connection(to);
}
void cl_base::delete_connect(cl_base* from, cl_base* to) {
	for (iter = from->connections.begin(); iter < from->connections.end(); iter++) {
		if (*iter == to) {
			connections.erase(iter, iter + 1);
		}
	}
}
void cl_base::set_condition(cl_base* ptr, int readiness) {
	if (get_parent(name) == nullptr) { find(name, this)->set_readiness(readiness); };
	if (get_parent(name) != nullptr && get_parent(name)->get_readiness() != 0) { find(name, this)->set_readiness(readiness); };
	if (find(name, this)->children.size() != 0 && find(name, this)->get_readiness() == 0) { reset_readiness(find(name, this)); };
}
string cl_base::emit(cl_base* ptr, string text, string result) {
	if (readiness) { return ""; };

}
string cl_base::get_way(cl_base* ptr) {
	if (ptr == this) { return ""; };
	return get_way(ptr->get_parent(ptr->get_name())) + '/' + ptr->get_name();
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