#ifndef USBDEVICE_H
#define USBDEVICE_H

#include <thread>
#include <libusb-1.0/libusb.h>

class UsbDevice
{
public:
  UsbDevice();


private:
  libusb_device_handle* mDeviceHandle;
};

#endif // USBDEVICE_H
