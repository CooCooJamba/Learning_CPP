#include <iostream>
#include <fstream>
#include "binaryFileManagement.h"
#include "hashTableManagement.h"
#include "binaryFileManagementHashTable.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "ru");
	testBinF();
	//testHeshT();
	testFinal();
	remove("s.txt");
	remove("b.dat");
	return 0;
}