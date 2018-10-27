#include "xparameters.h"
#include "xil_types.h"
#include "xgpio.h"
#include "xil_io.h"
#include "xil_exception.h"
#include <iostream>
using namespace std;

void printfield(XGpio GPIOInstance_ptr)
{
	cout<<GPIOInstance_ptr.BaseAddress<<endl;
	cout<<GPIOInstance_ptr.IsReady<<endl;
	cout<<GPIOInstance_ptr.InterruptPresent<<endl;
	cout<<GPIOInstance_ptr.IsDual<<endl;
}
int main()
{
	static XGpio GPIOInstance_Ptr;
	int xStatus;
	cout<<"Before Initialize:"<<endl;
	printfield(GPIOInstance_Ptr);
	xStatus = XGpio_Initialize(&GPIOInstance_Ptr,XPAR_AXI_GPIO_FOR_OUTPUT_DEVICE_ID);
	cout<<"After Initialize:"<<endl;
	printfield(GPIOInstance_Ptr);
	if(xStatus != XST_SUCCESS)
	{
	cout << "GPIO A Initialization FAILED" << endl;
	return 1;
	}
}
