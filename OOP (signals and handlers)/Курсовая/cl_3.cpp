#include "cl_3.h"
void cl_3::signal_3(string& command) {
	cout << endl << "Signal from " << get_way(this);
	command += " (class: 3)";
}
void cl_3::handler_3(string command) {
	cout << endl << "Signal to " << get_way(this) << " Text: " << command;
}