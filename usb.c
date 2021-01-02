//Thanks neur0n!!

#include <pspkernel.h>
#include <pspusb.h>
#include <pspusbstor.h>
#include <pspusbdevice.h>
#include <pspmodulemgr.h>
#include <pspsdk.h>

#include "common.h"

typedef struct
{
	char *path;
	int uid;
}UsbModuleList;

int StopUnloadModule(SceUID id)
{
	SceUID r = sceKernelStopModule(id ,0 ,NULL , NULL, NULL);
	if(r < 0) return r;
	return sceKernelUnloadModule(id);
}

static UsbModuleList usb_list[] = {
	{"flash0:/kd/semawm.prx"		, -1 },
	{"flash0:/kd/usbstor.prx"		, -1 },
	{"flash0:/kd/usbstormgr.prx"	, -1 },
	{"flash0:/kd/usbstorms.prx"		, -1 },
	{"flash0:/kd/usbstoreflash.prx"	, -1 },
	{"flash0:/kd/usbstorboot.prx"	, -1 },
};

#define USB_MODULE_CNT	(sizeof(usb_list)/sizeof(UsbModuleList))
void LoadUsbModules()
{
	int i;
	for(i=0;i<USB_MODULE_CNT;i++)
	{
		usb_list[i].uid = LoadStartModule( usb_list[i].path );
	}
}

void UnoadUsbModules()
{
	int i;
	for(i= (USB_MODULE_CNT - 1); i< 0 ;i--)
	{
		if( usb_list[i].uid >= 0)
		{
			StopUnloadModule(usb_list[i].uid);
			usb_list[i].uid = -1;
		}
	}
}
int connect_usb()
{
	static int connect_flag = 0;

	if( connect_flag )
	{
		sceUsbDeactivate(0);
		sceUsbStop(PSP_USBSTOR_DRIVERNAME, 0, 0);	
		sceUsbStop(PSP_USBBUS_DRIVERNAME, 0, 0);

		UnoadUsbModules();
	}
	else
	{
		LoadUsbModules();

		sceUsbStart(PSP_USBBUS_DRIVERNAME, 0, 0);
		sceUsbStart(PSP_USBSTOR_DRIVERNAME, 0, 0);
//			sceUsbstorBootSetCapacity(0x800000);
		sceUsbActivate( (model) ? 0x2D2:0x1C8 );
	}

	// select new
	connect_flag = 1- connect_flag;

	return connect_flag;
}

