#include "cl_4.h"
void cl_4::signal_4(string& command) {
	cout << endl << "Signal from " << get_way(this);
	command += " (class: 4)";
}
void cl_4::handler_4(string command) {
	cout << endl << "Signal to " << get_way(this) << " Text: " << command;
}