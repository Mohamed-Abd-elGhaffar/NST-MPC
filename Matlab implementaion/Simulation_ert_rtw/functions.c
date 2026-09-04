#include"rtwtypes.h"
#include<stdlib.h>
#include"functions.h"
#include"Simulation.h"
#include<math.h>
double simulate_batch(uint32_T _stop_time, uint32_T _trigger_time, real_T _gate_states[7], real_T _aggregate_states[9])
{
    Simulation_initialize();
    if (Simulation_M != NULL) {
        Simulation_M->Timing.TaskCounters.TID[1] = 0; 
    }
    for (int i=0; i<7; i++) {
            Simulation_DW.DiscreteTimeIntegrator_DSTATE_d[i] = _gate_states[i];
    }
    for (int i=0; i<9; i++) {
        Simulation_DW.DiscreteTimeIntegrator_DSTATE[i] = _aggregate_states[i];
    }
    for (uint32_T t = 0; t < _stop_time; t++) {
        Simulation_U.valveinput = (t>=_trigger_time)?0:1;
        Simulation_step();
    }
    return Simulation_Y.Out1;
}
