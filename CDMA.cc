/*
 * Liyuan Zhang
 * 27201044
 */

#include "xil_exception.h"
#include "xil_cache.h"
#include "xparameters.h"
#include <iostream>
using namespace std;

int main()
{
	u32* cdma_base_address = (u32*)XPAR_AXI_CDMA_0_BASEADDR;
	u32* source_address = (u32*)XPAR_PS7_DDR_0_S_AXI_HP0_BASEADDR;
	u32* destination_address = (u32*)XPAR_PS7_DDR_0_S_AXI_HP2_BASEADDR;
	int status;

	for(int i=0;i<10;i++)
	{
		*(source_address+i) = i;
		status = *(source_address+i);
		cout<<"source address [" << i << "] is: ";
		cout << std::hex << status << endl;
	}

	for(int i=0;i<10;i++)
	{
		*(destination_address+i) = -i;
		status = *(destination_address+i);
		cout<<"destination address [" << i << "] is: ";
		cout << std::hex << status << endl;
	}

	*(cdma_base_address) = 0x6; //reset
	status = *(cdma_base_address+1);
	cout<<"The status before configure just after reset is "<<status<<", not idle!"<<endl;
	*(cdma_base_address) = 0x2; //simple mode
	status = *(cdma_base_address+1);
	cout<<"The status after configuring simple mode is "<<status<<", idle!"<<endl;

	*(cdma_base_address+6) = XPAR_PS7_DDR_0_S_AXI_HP0_BASEADDR;  //load in SA
	*(cdma_base_address+8) = XPAR_PS7_DDR_0_S_AXI_HP2_BASEADDR; //load in DA
	status = *(cdma_base_address+1);
	cout<<"After load in SA & DA, status is: ";
	cout << std::hex << status << endl;
	Xil_DCacheFlush();  //flush the cache
	status = *(cdma_base_address+1);
	cout<<"After flushing the cache, status is: ";
	cout << std::hex << status << endl;
	*(cdma_base_address+10) = 0x28;  //write in BTT 0x00000028, means 40 bytes to transfer (10 integers), initiates simple DMA transfer
	status = *(cdma_base_address+1);
	cout<<"When transfer bytes, status is: ";
	cout << std::hex << status << endl;
	while(status!=2)  //when status!=2 => not idle, wait...
	{
		status = *(cdma_base_address+1) & 0x2;  //wait till complete transfer and idle again
	}
	cout<<"After transfer, status is: ";
	cout << std::hex << status << endl;
	for(int i=0;i<10;i++)
	{
		status = *(source_address+i);
		cout<<"Now, source address [" << i << "] is: ";
		cout << std::hex << status << endl;
	}

	for(int i=0;i<10;i++)
	{
		status = *(destination_address+i);
		cout<<"Now, destination address [" << i << "] is: ";
		cout << std::hex << status << endl;
	}
	return 0;
}
