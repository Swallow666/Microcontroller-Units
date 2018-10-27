#include "stdbool.h"
#include "xparameters.h"
#include "xil_io.h"
#include "xil_exception.h"
#include "xtmrctr.h"
#include "unistd.h"

#include <iostream>
using namespace std;

int main()
{
	u32* Timer_Ptr = (u32*)XPAR_TMRCTR_0_BASEADDR;
	unsigned int capture_val, new_capture_val, time_between_sw5;
	cout<<"###Application Start###"<<endl;
	*(Timer_Ptr) = 0x019;
	*(Timer_Ptr+1) = 0;
	*(Timer_Ptr) = 0x039;
	*(Timer_Ptr) = 0x099;
	while(*(Timer_Ptr+1)==0)
	{
		//wait for sw5
	}
	capture_val = *(Timer_Ptr+1);
	sleep(2);
	while(*(Timer_Ptr+1)==capture_val)
	{
		//wait again for sw5
	}
	new_capture_val = *(Timer_Ptr+1);
	time_between_sw5 = new_capture_val - capture_val;
	cout<<"The time first press sw5 is "<<capture_val<<" clock cycles."<<endl;
	cout<<"The time second press sw5 is "<<new_capture_val<<" clock cycles."<<endl;
	cout<<"The time between sw5 press is "<<time_between_sw5<<" clock cycles."<<endl;
	return 0;
}
