#ifndef USBDEVICEMANAGER_H
#define USBDEVICEMANAGER_H

#include <libusb-1.0/libusb.h>

class UsbDeviceManager {
 public:
  enum result {
    E_ALREADYINITIALIZED=0x8000000,
    OK=0,
  };

  UsbDeviceManager();
  ~UsbDeviceManager();

  int initialize();

 private:
  libusb_context* mContext;
};

#endif  // USBDEVICEMANAGER_H
