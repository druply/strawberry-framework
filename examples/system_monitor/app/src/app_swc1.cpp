/*
 * app_swc1.c
 *
 *  Created on: Aug 20, 2020
 *      Author: Rodolfo.Ortega
 */

#include "system_types.hpp"
#include "app_swc.hpp"


// include your headers here!!
#include "sys_mon.hpp"
system_exception_T except;

void app_swc1_init(void) {
	except = sys_OK;
}

void rte_input_swc1(void) {
	//bind rte  signals with swc input signals.
	//double input = BtS_ActivationState[index_ctr];
}

void rte_output_swc1(void) {
	//bind rte signals with swc output signals.
	//output1[index_ctr] = 5;
}

void app_swc1(void) {
	
    static int ctr = 0, ctr2 = 0;
	ctr++;

	if(ctr == 150) {
		except = sys_Restart;
		SetSystemException(except);
		ctr = 0;
		ctr2++;

		if(ctr2 == 10) {
			except = sys_Taskoverrun;
			SetSystemException(except);
		}
	}
    // read inputs from rte
	rte_input_swc1();

	//write outputs to rte
	rte_output_swc1();
    
}


void app_swc1_deinit(void) {


}