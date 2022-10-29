#include "cl_1.h"
void cl_1::signal_1(string& command) {
	cout << endl << "Signal from /";
	command += " (class: 1)";
}
void cl_1::handler_1(string command) {
	cout << endl << "Signal to / Text: " << command;
}