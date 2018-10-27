#include "xparameters.h"
#include "xil_types.h"
#include "xgpio.h"
#include "xil_io.h"
#include "xil_exception.h"
#include <iostream>
using namespace std;
int main()
{
static XGpio GPIOInstance_Ptr;
int xStatus;
cout << "#### Application Starts ###" << endl;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//Step-1: AXI GPIO Initialization
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
xStatus = XGpio_Initialize(&GPIOInstance_Ptr,
XPAR_AXI_GPIO_FOR_OUTPUT_DEVICE_ID);
if(xStatus != XST_SUCCESS)
{
cout << "GPIO A Initialization FAILED" << endl;
return 1;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//Step-2: AXI GPIO Set the Direction
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//XGpio_SetDataDirection(XGpio *InstancePtr, unsigned Channel,
// u32 DirectionMask);
//we use only channel 1, and 0 is the parameter for output
// 1 is the parameter for input
XGpio_SetDataDirection(&GPIOInstance_Ptr, 1, 0);
int ted_data; // use int since cin does not know how to
// handle u8 , this is the data which will be sent
// to the GPIO using the XGpio_DiscreteWrite
// function call
for(int i = 0 ; i < 9 ; i++)
{
cout << "Enter the data to be sent to the GPIO" << endl;
cin >> ted_data;
// cast the data to u8 and send i to the GPIO
XGpio_DiscreteWrite(&GPIOInstance_Ptr, 1, (u8) ted_data);
cout<<ted_data<<endl;
}
cout << "End of program" << endl;
return 0;
}
