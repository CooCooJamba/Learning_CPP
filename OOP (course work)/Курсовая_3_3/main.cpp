#include <iostream>
#include "application.h"
using namespace std;
int main() {
	application object;
	object.build_tree();
	object.set_connections();
	return object.exec_app();
	return 0;
}