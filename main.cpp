//============================================================================
// Name        : cortexAlinux.cpp
// Author      : Rodolfo Ortega
// Version     :
// Copyright   : CNXMOTION copyright
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "sys_mon.hpp"

using namespace std;

int main() {

	//cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	SystemInit();
	SystemStart();

	return 0;
}
