#include "cl_2.h"
void cl_2::signal_2(string& command) {
	cout << endl << "Signal from " << get_way(this);
	command += " (class: 2)";
}
void cl_2::handler_2(string command) {
	cout << endl << "Signal to " << get_way(this) << " Text: " << command;
}