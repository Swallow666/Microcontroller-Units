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
	u32* timer = (u32*)0x42800000;

	int status;

	for(int i=0;i<2097151;i++)  //2097151 is the maximum integers can transfer,
	{
		*(source_address+i) = i;
	}

	for(int i=0;i<2097151;i++)	//because 2097151*4 = 8388604 bytes, maximum is 8388607 bytes
	{
		*(destination_address+i) = -i;
	}

	*(cdma_base_address) = 0x6; //reset
	*(cdma_base_address) = 0x2; //simple mode
	*(cdma_base_address+6) = XPAR_PS7_DDR_0_S_AXI_HP0_BASEADDR;  //load in SA
	*(cdma_base_address+8) = XPAR_PS7_DDR_0_S_AXI_HP2_BASEADDR; //load in DA
	Xil_DCacheFlush();  //flush the cache

	unsigned int count;
	*(timer) = 0x001;  //capture mode
	*(timer + 1) = 0;  //load = 0
	*(timer) = 0x021;  //load 0
	*(timer) = 0x001;
	*(timer) = 0x081;  //start timer
	*(timer) = 0x001;  //end timer
	count = *(timer + 2);
	cout<<"It takes "<<count<<" cc to access memory, start timer and close timer."<<endl;

	*(timer) = 0x021;
	*(timer) = 0x001;
	*(cdma_base_address+10) = 0x1000;  //write in BTT 0x1000 = 4096 bytes, 1024 integers
	*(timer) = 0x081;
	status = *(cdma_base_address+1);
	while(status!=2)  //when status!=2 => not idle, wait...
	{
		status = *(cdma_base_address+1) & 0x2;  //wait till complete transfer and idle again
	}
	*(timer) = 0x001;
	count = *(timer + 2);
	cout<<"It takes "<<count<<" cc to transfer 1024 integers by BTT, CDMA."<<endl;

	*(timer) = 0x021;
	*(timer) = 0x001;
	*(timer) = 0x081;
	for(int i=0;i<1024;i++)
	{
		*(destination_address+i) = *(source_address+i);
	}
	*(timer) = 0x001;
	count = *(timer + 2);
	cout<<"It takes "<<count<<" cc to transfer 1024 integers, NOT by CDMA."<<endl;

	*(timer) = 0x021;
	*(timer) = 0x001;
	*(cdma_base_address+10) = 0x4000;  //write in BTT 0x4000 = 16384 bytes, 4096 integers
	*(timer) = 0x081;
	status = *(cdma_base_address+1);
	while(status!=2)  //when status!=2 => not idle, wait...
	{
		status = *(cdma_base_address+1) & 0x2;  //wait till complete transfer and idle again
	}
	*(timer) = 0x001;
	count = *(timer + 2);
	cout<<"It takes "<<count<<" cc to transfer 4096 integers by BTT, CDMA."<<endl;

	*(timer) = 0x021;
	*(timer) = 0x001;
	*(timer) = 0x081;
	for(int i=0;i<4096;i++)
	{
		*(destination_address+i) = *(source_address+i);
	}
	*(timer) = 0x001;
	count = *(timer + 2);
	cout<<"It takes "<<count<<" cc to transfer 4096 integers, NOT by CDMA."<<endl;

	*(timer) = 0x021;
	*(timer) = 0x001;
	*(cdma_base_address+10) = 0x8000;  //write in BTT 0x8000 = 32768 bytes, 8192 integers
	*(timer) = 0x081;
	status = *(cdma_base_address+1);
	while(status!=2)  //when status!=2 => not idle, wait...
	{
		status = *(cdma_base_address+1) & 0x2;  //wait till complete transfer and idle again
	}
	*(timer) = 0x001;
	count = *(timer + 2);
	cout<<"It takes "<<count<<" cc to transfer 8192 integers by BTT, CDMA."<<endl;

	*(timer) = 0x021;
	*(timer) = 0x001;
	*(timer) = 0x081;
	for(int i=0;i<8192;i++)
	{
		*(destination_address+i) = *(source_address+i);
	}
	*(timer) = 0x001;
	count = *(timer + 2);
	cout<<"It takes "<<count<<" cc to transfer 8192 integers, NOT by CDMA."<<endl;

	*(timer) = 0x021;
	*(timer) = 0x001;
	*(cdma_base_address+10) = 0x10000;  //write in BTT 0x10000 = 65536 bytes, 16384 integers
	*(timer) = 0x081;
	status = *(cdma_base_address+1);
	while(status!=2)  //when status!=2 => not idle, wait...
	{
		status = *(cdma_base_address+1) & 0x2;  //wait till complete transfer and idle again
	}
	*(timer) = 0x001;
	count = *(timer + 2);
	cout<<"It takes "<<count<<" cc to transfer 16384 integers by BTT, CDMA."<<endl;

	*(timer) = 0x021;
	*(timer) = 0x001;
	*(timer) = 0x081;
	for(int i=0;i<16384;i++)
	{
		*(destination_address+i) = *(source_address+i);
	}
	*(timer) = 0x001;
	count = *(timer + 2);
	cout<<"It takes "<<count<<" cc to transfer 16384 integers, NOT by CDMA."<<endl;

	*(timer) = 0x021;
	*(timer) = 0x001;
	*(cdma_base_address+10) = 0x20000;  //write in BTT 0x20000 = 131072 bytes, 32768 integers
	*(timer) = 0x081;
	status = *(cdma_base_address+1);
	while(status!=2)  //when status!=2 => not idle, wait...
	{
		status = *(cdma_base_address+1) & 0x2;  //wait till complete transfer and idle again
	}
	*(timer) = 0x001;
	count = *(timer + 2);
	cout<<"It takes "<<count<<" cc to transfer 32768 integers by BTT, CDMA."<<endl;

	*(timer) = 0x021;
	*(timer) = 0x001;
	*(timer) = 0x081;
	for(int i=0;i<32768;i++)
	{
		*(destination_address+i) = *(source_address+i);
	}
	*(timer) = 0x001;
	count = *(timer + 2);
	cout<<"It takes "<<count<<" cc to transfer 32768 integers, NOT by CDMA."<<endl;

	*(timer) = 0x021;
	*(timer) = 0x001;
	*(cdma_base_address+10) = 0x400000;  //write in BTT 0x400000 = 4194304 bytes, 1048576 integers
	*(timer) = 0x081;
	status = *(cdma_base_address+1);
	while(status!=2)  //when status!=2 => not idle, wait...
	{
		status = *(cdma_base_address+1) & 0x2;  //wait till complete transfer and idle again
	}
	*(timer) = 0x001;
	count = *(timer + 2);
	cout<<"It takes "<<count<<" cc to transfer 1048576 integers by BTT, CDMA."<<endl;

	*(timer) = 0x021;
	*(timer) = 0x001;
	*(timer) = 0x081;
	for(int i=0;i<1048576;i++)
	{
		*(destination_address+i) = *(source_address+i);
	}
	*(timer) = 0x001;
	count = *(timer + 2);
	cout<<"It takes "<<count<<" cc to transfer 1048576 integers, NOT by CDMA."<<endl;

	*(timer) = 0x021;
	*(timer) = 0x001;
	*(cdma_base_address+10) = 0x7FFFFC;  //write in BTT 0x7FFFFC = 8388604 bytes, 2097151 integers
	*(timer) = 0x081;
	status = *(cdma_base_address+1);
	while(status!=2)  //when status!=2 => not idle, wait...
	{
		status = *(cdma_base_address+1) & 0x2;  //wait till complete transfer and idle again
	}
	*(timer) = 0x001;
	count = *(timer + 2);
	cout<<"It takes "<<count<<" cc to transfer 2097151 integers by BTT, CDMA."<<endl;

	*(timer) = 0x021;
	*(timer) = 0x001;
	*(timer) = 0x081;
	for(int i=0;i<2097151;i++)
	{
		*(destination_address+i) = *(source_address+i);
	}
	*(timer) = 0x001;
	count = *(timer + 2);
	cout<<"It takes "<<count<<" cc to transfer 2097151 integers, NOT by CDMA."<<endl;

	cout<<"End of Application."<<endl;
	return 0;
}

