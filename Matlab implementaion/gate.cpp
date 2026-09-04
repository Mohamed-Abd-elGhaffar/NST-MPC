#include<iostream>
#include<pigpio.h>
#include"gate.hpp"
using namespace std;
void gate_initialize()
{
	if (gpioInitialise() < 0)
        {
                cout << "GPIO Error";
        }
        else
        {
                cout << "GPIO initialized";
        }

        gpioSetMode(gate, PI_OUTPUT);
}

void gate_state(int out)
{
	 if(out == 0)
	 {
		 gpioWrite(gate,out);
		 cout << "Gate opened" << endl;
	 }
	 else if(out == 1)
	 {
		 gpioWrite(gate,out);
		 cout << "Gate closed" << endl;
	 }
	 else
	 {
		 cout << "invalid gate action" << endl;
	 }
}
