#include <stdlib.h>
#include <stdio.h>
#include "application.h"
int main() {
	application object;
	object.build_tree();
	object.set_connections();
	return object.exec_app();
}