#ifndef SYSTASKS_HPP_
#define SYSTASKS_HPP_

#include "sys_config.hpp"
void SystemInitTasks(void);
void SystemDeInitTasks(void);

void SystemTask0(void);
#define SYS_TASKS_NUM_OF_THREADS          1

#define SYS_NUM_OF_NRT_THREADS_  0
#endif //SYSTASKS_HPP_ 

