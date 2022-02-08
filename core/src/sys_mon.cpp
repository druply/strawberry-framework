/*
 * cxsys.c
 *
 *  Created on: Sep 18, 2020
 *      Author: Rodolfo.Ortega
 */



#include "sys_mon.hpp"
#include "rtsim.hpp"
#include <mutex>
#include "sys_logger.hpp"
#include "sys_tasks.hpp"


system_state_T sys_state = sys_INACTIVE;

static int warning_fault_ctr;

std::mutex cxsys_mtx;           // mutex for critical section

/**
 * Initialize OS
 */
void SystemInit(void) {

	warning_fault_ctr = 0;

	sys_state = sys_INIT;

    SystemLog("Initializing OS");
	// init rtos
	OsInit();

    SystemLog("Initializing Tasks");
	// Initialize tasks and services
	SystemInitTasks();
}

/**
 * Start OS
 */
void SystemStart(void) {
	// change OS state
	sys_state = sys_RUNNING;

	SystemLog("Starting OS");
    // start OS
	OsStart();
}

void GetSystemState(system_state_T *state) {

	// lock mutex for critical section
	cxsys_mtx.lock();

	*state = sys_state;

	// unlock mutex
	cxsys_mtx.unlock();
}


void SetSystemException(system_exception_T exception) {
	if(exception == sys_Taskoverrun) {
		sys_state = sys_Sys_ERROR;
	}

	if(exception == sys_Taskdelayed) {
        
        warning_fault_ctr++;
		SystemLog("task delayed");
	}
}

/**
 * Monitor System
 this should be called every 10ms for accurate monitoring
 */
void SystemMonitor(void) {
    // declare variables
    static int loop_ctr = 0;
    loop_ctr++;

    // monitor faults in the system
    if((loop_ctr%100) == 1) {

        // if there are more than 10 faults then stop the system
        if(warning_fault_ctr > 10) {
            sys_state = sys_Sys_ERROR;
            SystemLog("tasks are out of sync, Stopping system...");
        }

        warning_fault_ctr = 0;
    }

}

/**
 * De-Initialize OS
 */
void SystemDeinit(void) {
	sys_state = sys_INACTIVE;
    SystemLog("Deinitializing system");

}
