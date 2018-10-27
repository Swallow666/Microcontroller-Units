#include "stdbool.h"
#include "xparameters.h"
#include "xil_types.h"
#include "xgpio.h"
#include "xil_io.h"
#include "xil_exception.h"
#include "xtmrctr.h"
#include <iostream>
using namespace std;
//all comment in the lab manual
int main()
{
	static XGpio GPIOInstance_Ptr;
	u32* Timer_Ptr = (u32*)XPAR_TMRCTR_0_BASEADDR;
	int xStatus;
	cout<<"#### Let's begin####"<<endl;
	xStatus = XGpio_Initialize(&GPIOInstance_Ptr,XPAR_AXI_GPIO_FOR_OUTPUT_DEVICE_ID);
	if(xStatus != XST_SUCCESS)
	{
		cout<<"GPIO A Initialization failed"<<endl;
		return 1;
	}
	XGpio_SetDataDirection(&GPIOInstance_Ptr,1,0);

	*(Timer_Ptr) = 0x001;
	*(Timer_Ptr+1) = 0;
	*(Timer_Ptr) = 0x021;
	*(Timer_Ptr) = 0x081;
	XGpio_DiscreteWrite(&GPIOInstance_Ptr,1,0xFF);
	*(Timer_Ptr) = 0x001;
	unsigned int count;
	count = *(Timer_Ptr+2);
	cout<<"Count: "<<count<<endl;
	cout<<"Now reload timer to 0"<<endl;
	*(Timer_Ptr) = 0x021;
	*(Timer_Ptr) = 0x001;
	count = *(Timer_Ptr+2);
	cout<<"After  reload, Count: "<<count<<endl;
	*(Timer_Ptr) = 0x081;
	*(Timer_Ptr) = 0x001;
	count = *(Timer_Ptr+2);
	cout<<"Time to access two times memory to start and stop timer counter is "<<count<<endl;
	return 0;
}
