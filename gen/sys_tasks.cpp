/*
 * sys_tasks.cpp
 *
 *  Created on: Aug 18, 2021
 *      Author: Rodolfo.Ortega
 */

#include "system_types.hpp"
#include "sys_tasks.hpp"
#include <iostream>
/**
 * Task 0 task
 * execute every 10ms to get a real time execution
 */
void SystemTask0(void) {

   static uint16_t thread0_ctr;

   // 10ms calls go here
    std::cout << "task 0" << std::endl;

   if ((thread0_ctr % 2) == 0) {
       // 20ms calls go here
   }

    if (((thread0_ctr - 2) % 10) == 0) {
       // 100ms calls go here
   }

    if (((thread0_ctr - 3) % 100) == 0) {
       // 1000ms calls go here
   }
   // Initial loop executes when the TaskLoopCount is 0
   if (thread0_ctr >= 9999)
   {
       thread0_ctr = 0;
   }
   else {
       thread0_ctr++;;
   }
}
/**
 * Task 1 task
 * execute every 10ms to get a real time execution
 */
void SystemTask1(void) {


   static uint16_t thread1_ctr;
   // 10ms calls go here
   std::cout << "task 1" << std::endl;

   if ((thread1_ctr % 2) == 0) {
       // 20ms calls go here
   }

   if (((thread1_ctr - 1) % 5) == 0)  {
       // 50ms calls go here
   }

    if (((thread1_ctr - 2) % 10) == 0) {
       // 100ms calls go here
   }

    if (((thread1_ctr - 3) % 100) == 0) {
       // 1000ms calls go here
   }
   // Initial loop executes when the TaskLoopCount is 0
   if (thread1_ctr >= 9999)
   {
       thread1_ctr = 0;
   }
   else {
       thread1_ctr++;;
   }
}
/**
 * Task 2 task
 * execute every 10ms to get a real time execution
 */
void SystemTask2(void) {


   static uint16_t thread2_ctr;
   // 10ms calls go here

   if ((thread2_ctr % 2) == 0) {
       // 20ms calls go here
   std::cout << "task 2" << std::endl;
   }

   if (((thread2_ctr - 1) % 5) == 0)  {
       // 50ms calls go here
   }

    if (((thread2_ctr - 2) % 10) == 0) {
       // 100ms calls go here
   }

    if (((thread2_ctr - 3) % 100) == 0) {
       // 1000ms calls go here
   }
   // Initial loop executes when the TaskLoopCount is 0
   if (thread2_ctr >= 9999)
   {
       thread2_ctr = 0;
   }
   else {
       thread2_ctr++;;
   }
}

