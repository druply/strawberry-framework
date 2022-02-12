/*
 * sys_tasks.cpp
 *
 *  Created on: Aug 18, 2021
 *      Author: Rodolfo.Ortega
 */

#include "system_types.hpp"
#include "sys_tasks.hpp"
#include "app_swc.hpp"
#include "sys_timer.hpp"
#ifdef ENABLE_SYS_TIMER
#include "sys_logger.hpp"
#endif //ENABLE_SYS_TIMER
#include "sys_tasks.hpp"


#ifdef ENABLE_SYS_TIMER
struct timespec tmr1, tmr2;
double time_elapsed;
#endif //ENABLE_SYS_TIMER

/**
 * Init tasks
 * Initialize system tasks
 */
void SystemInitTasks(void) {
  //pi4.InitEcua();
}


/**
 * Task 0 task
 * execute every cycle to get a real time execution
 */
void SystemTask0(void) {

   static uint16_t thread0_ctr;

#ifdef ENABLE_SYS_TIMER
   UpdateTimer(&tmr1);
#endif //ENABLE_SYS_TIMER
   // 1x calls go here

   if ((thread0_ctr % 2) == 0) {
       // 2x calls go here
   //usonicsDrv();
   //encodersDrv();
   //tcpDrv();
   //lidarDrv();
   //cameraDrv();
   app_swc1();
   }

    if (((thread0_ctr - 2) % 10) == 0) {
       // 10x calls go here
   }

    if (((thread0_ctr - 3) % 100) == 0) {
       // 100x calls go here
   }
   // Initial loop executes when the TaskLoopCount is 0
   if (thread0_ctr >= 9999)
   {
       thread0_ctr = 0;
   }
   else {
       thread0_ctr++;;
   }

#ifdef ENABLE_SYS_TIMER
   UpdateTimer(&tmr2);
   time_elapsed = GetTimeElapsedUs(&tmr1, &tmr2);
   DebugLog(time_elapsed, "total time in micros: ");
#endif //ENABLE_SYS_TIMER

}

