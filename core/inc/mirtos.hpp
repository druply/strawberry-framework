#pragma once

#include <thread>
#include <chrono>
#include <vector>
#include <string>

/*
  Structure for tasks
*/
template <typename T>
void newThread(void (*fptr)(int), T value) {
	int ctr = 0;
	while(ctr<20) {
		auto start = std::chrono::high_resolution_clock::now();
		ctr++;

		fptr(value);
					
		auto end = std::chrono::high_resolution_clock::now();	
		auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - 
		start);									   		

		std::this_thread::sleep_for(std::chrono::milliseconds(value) - duration);
	}
}

typedef struct {
	void (*fptr)(int);
	int cycle;
	std::string name;
	int type;
} Task_T;

void createTask(void (*func)(int), std::string name_tmp, int cycle_tmp, int type_tmp);
void startScheduler(void);

