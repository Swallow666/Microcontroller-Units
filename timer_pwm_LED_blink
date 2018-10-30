#include "stdbool.h"
#include "xparameters.h"
#include "xil_io.h"
#include "xil_exception.h"
#include "xtmrctr.h"

#include <iostream>
using namespace std;

int main()
{
	u32* timer_ptr = (u32*)XPAR_TMRCTR_0_BASEADDR;
	u32* second_timer_ptr = (u32*)0x42800010;     //TCSR1 address
	unsigned int clk_frequency = XPAR_AXI_TIMER_0_CLOCK_FREQ_HZ;
	float pwm_period, pwm_duty_cycle;

	*(timer_ptr) = 0x206;        //PWM enable, count down
	*(second_timer_ptr) = 0x206;
	*(timer_ptr + 1) = 0xFFFFFFFF;
	*(second_timer_ptr + 1)=0xFFFFFFFF;
	*(timer_ptr) = 0x226;
	*(second_timer_ptr) = 0x226;
	while(true)
	{
		cout<<"Enter the desired PWM period in seconds: "<<endl;
		cin>>pwm_period;
		cout<<"Enter the desired duty cycle in seconds: "<<endl;
		cin>>pwm_duty_cycle;
		*(timer_ptr + 1) = pwm_period * clk_frequency - 2;
		*(second_timer_ptr + 1) = pwm_duty_cycle * clk_frequency -2;
		*(timer_ptr) = 0x286;
		*(second_timer_ptr) = 0x286;
	}
	return 0;
}

