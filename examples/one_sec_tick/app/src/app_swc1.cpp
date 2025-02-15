/*
 * app_swc1.c
 *
 *  Created on: Aug 20, 2020
 *      Author: Rodolfo.Ortega
 */

#include "system_types.hpp"
#include "app_swc.hpp"


// include your headers here!!
#include <iostream>


void app_swc1_init(void) {

}

void rte_input_swc1(void) {
	//bind rte  signals with swc input signals.
	//double input = BtS_ActivationState[index_ctr];
}

void rte_output_swc1(void) {
	//bind rte signals with swc output signals.
	//output1[index_ctr] = 5;
}

void AppSwc1(void) {
	
    static int ctr = 0;

    // read inputs from rte
	rte_input_swc1();

	ctr++;
    // check if 1000 ms have elapsed
	if (ctr == 1000) {
		std::cout << "One second tick" << std::endl;
		ctr = 0;
	}

	//write outputs to rte
	rte_output_swc1();
    
}


void app_swc1_deinit(void) {


}