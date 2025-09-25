#pragma once

#include <thread>
#include <chrono>
#include <vector>
#include <string>
#include <mutex>
#include "strawberry.hpp"

#include <iostream>

/*
  Structure for tasks
*/
typedef struct {
	void (*fptr)(TaskParams_T*);
	TaskParams_T params;
} Task_T;

/*
class enum for
the types of tasks
*/
enum class TaskType {
	Cyclic,
	OneTime,
	NonCyclic
};

/*
class enum for
the system state
*/
enum class SysState {
	Running,
	Stopped
};

//local mutex to avoid race conditions
std::mutex mtx_local;

//prototype for function
static SysState getTaskState();

// prototype to stop system
void stopScheduler(void);


/*
 Task function template
*/
template <typename T>
void newThread(void (*fptr)(TaskParams_T*), T parameters) {
	//local variable to monitor system state
	SysState sys_state;
	
	//enter an infinite loop as long as system is running
	while(sys_state == SysState::Running) {
		
		//lock mutex
		mtx_local.lock();
		//get the start timestamp
		auto start = std::chrono::high_resolution_clock::now();
		//update the system state
		sys_state = getTaskState();
		mtx_local.unlock();

		//execute the function
		fptr(&parameters);
		
		//lock mutex
		mtx_local.lock();		
		//get the end timestamp
		auto end = std::chrono::high_resolution_clock::now();	
		//calculate the duration of this function execution time
		auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - 
		start);	
		
		// if excution time is greater than cycle time the thow exception
		if(std::chrono::milliseconds(parameters.cycle) < duration) {
			stopScheduler();
			throw std::runtime_error("Runtime is bigger than cycle time in task: " + parameters.name);

		}

		//calculate sleep time to accomplish real time
		auto sleep_tmp = (std::chrono::milliseconds(parameters.cycle) - duration);	

		
		//unlock mutex
		mtx_local.unlock();
			
		//sleep thread if no exception occured						   		
		try {
			std::this_thread::sleep_for(sleep_tmp);
		}

		// catch exceptions
		catch(std::runtime_error &ex) {
			std::cout <<  ex.what() << std::endl;
		}
					
		catch(std::exception &ex) {
			std::cout <<  ex.what() << std::endl;
		}
		
	}
}

