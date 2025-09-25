#pragma once


/*
class enum for
the types of tasks
*/
enum class task_type_t {
	Cyclic,
	OneTime,
	NonCyclic
};

/*
struct for task parameters
*/
typedef struct {
	int cycle;
	std::string name;
	task_type_t type;
} task_params_t;



void createTask(void (*func)(task_params_t*), std::string name_tmp, int cycle_tmp, task_type_t type_tmp);
void startScheduler(void);

