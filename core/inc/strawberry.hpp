#pragma once

typedef struct {
	int cycle;
	std::string name;
	int type;
} TaskParams_T;


void createTask(void (*func)(TaskParams_T*), std::string name_tmp, int cycle_tmp, int type_tmp);
void startScheduler(void);

