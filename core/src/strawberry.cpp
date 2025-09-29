
#include "strawberry_private.hpp"
#include <iostream>

namespace strawberry {

// vector of tasks to be executed
std::vector<Task_T> tasks;

//system state variable
SysState sys_state_local;

/*
 Create a task and
 add it to the vector
*/
void createTask(void (*func)(task_params_t*), std::string name_tmp, int cycle_tmp, task_type_t type_tmp) {

	// create a temporary structure task
	Task_T task_tmp;
	
	//assign the function to be executed
	task_tmp.fptr = func;
	//assigne the cycle at which it will run
	task_tmp.params.cycle = cycle_tmp;
	// name of the function
	task_tmp.params.name = name_tmp;
	// type of task to be executed
	task_tmp.params.type = type_tmp;		

	// add task to the vector
	tasks.push_back(task_tmp);	
}


/*
Start the scheduler
create the Threads and run them
*/
void startScheduler(void) {
	//create an array of threads
	std::thread threads[tasks.size()];
	//iteration variable
	int x =0;
	//system state is running
	sys_state_local = SysState::Running;
	
	// assign the functions to be executed to the threads
	for (auto tsk : tasks) {

		switch(tsk.params.type) {
		
			case task_type_t::Cyclic:			
			threads[x++] = std::thread(newCyclicThread<task_params_t>, tsk.fptr, tsk.params);
			break;
			
			case task_type_t::OneTime:
			break;
			
			case task_type_t::NonCyclic:
			break;
			
			default:
			break;
		};
		

	}
	
	// set threads as join
	for (x=0; x<tasks.size(); x++) {
		threads[x].join();
	}
}


/*
Get thecurrent system state
*/
static SysState getTaskState() {
	return sys_state_local;
}

/*
Stop scheduler
*/
void stopScheduler(void) {
	// set system state to stopped
	sys_state_local = SysState::Stopped;
}


}
