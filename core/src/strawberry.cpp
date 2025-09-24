
#include "strawberry_private.hpp"
//#include "strawberry.hpp"

// vector of tasks to be executed
std::vector<Task_T> tasks;

//system state variable
SysState sys_state_local;

/*
 Create a task and
 add it to the vector
*/
void createTask(void (*func)(TaskParams_T*), std::string name_tmp, int cycle_tmp, int type_tmp) {

	// create a temporary structure task
	Task_T task_tmp;
	
	//assign the function to be executed
	task_tmp.fptr = func;
	//assigne the cycle at which it will run
	task_tmp.cycle = cycle_tmp;
	// name of the function
	task_tmp.name = name_tmp;
	// type of task to be executed
	task_tmp.type = type_tmp;		

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
	for (auto i : tasks) {
		
		i.params.cycle = i.cycle;
		i.params.name = i.name;
		i.params.type = i.type;
		//i.fptr(i.cycle);
		threads[x++] = std::thread(newThread<TaskParams_T>, i.fptr, i.params);

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

