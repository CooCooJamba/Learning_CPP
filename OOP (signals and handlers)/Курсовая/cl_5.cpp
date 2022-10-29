#include "cl_5.h"
void cl_5::signal_5(string& command) {
	cout << endl << "Signal from " << get_way(this);
	command += " (class: 5)";
}
void cl_5::handler_5(string command) {
	cout << endl << "Signal to " << get_way(this) << " Text: " << command;
}