#include "mirtos.hpp"

std::vector<Task_T> tasks;

void createTask(void (*func)(int), std::string name_tmp, int cycle_tmp, int type_tmp) {

	Task_T task_tmp;
	
	task_tmp.fptr = func;
	task_tmp.cycle = cycle_tmp;
	task_tmp.name = name_tmp;
	task_tmp.type = type_tmp;		

	
	tasks.push_back(task_tmp);
}

void startScheduler(void) {

	std::thread threads[tasks.size()];
	int x =0;
	
	for (auto i : tasks) {
		//i.fptr(i.cycle);
		threads[x++] = std::thread(newThread<int>, i.fptr, i.cycle);

	}
	
	for (x=0; x<tasks.size(); x++) {
		threads[x].join();
	}
}

