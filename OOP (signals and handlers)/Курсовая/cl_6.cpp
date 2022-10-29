#include "cl_6.h"
void cl_6::signal_6(string& command) {
	cout << endl << "Signal from " << get_way(this);
	command += " (class: 6)";
}
void cl_6::handler_6(string command) {
	cout << endl << "Signal to " << get_way(this) << " Text: " << command;
}