//============================================================================
// Name        : main.cpp
// Author      : Rodolfo Ortega
// Version     :
// Copyright   : GNU License
// Description : Main file for strawberry framework
//============================================================================

//include headers
#include <iostream>
#include "sys_mon.hpp"


int main() {
	//declare system state
	static system_state_T state = sys_INACTIVE;
	//decalre system running
	static bool running = true;

	// Initialize system
	SystemInit();
	//enter infitine loop while system is running
	while(running) {
		//get system state
		GetSystemState(&state);

		switch(state) {
			//choose funciton based on system state
			case sys_INIT:				
				SystemInit();				
				break;
			
			case sys_RUNNING:
				SystemStart();				
				break;
			
			case sys_STOP:
				//stop running system
				running = false;
				break;
			
			default:
				break;
		}
	}

	//de initialize system
	SystemDeinit();
	

	return 0;
}
