#ifndef USBDEVICEMANAGER_H
#define USBDEVICEMANAGER_H

#include "utils/BackgroundThread.h"

#include <functional>
#include <libusb-1.0/libusb.h>
#include <list>
#include <string>

class UsbDevice;

class UsbDeviceManager {
 public:
  enum result {
    E_ALREADYINITIALIZED=0x8000000,
    E_NODEVICES,
    OK=0,
  };
  typedef
  std::function<
    bool (const libusb_device_descriptor&,
          const libusb_config_descriptor&)
  > enumerationcallback_t;

  UsbDeviceManager();
  ~UsbDeviceManager();

  int initialize();

  int enumerateAvailableDevices(const enumerationcallback_t& cb);


 private:
  libusb_context* mContext;

  std::list<UsbDevice*> mOpenDevices;

  BackgroundThread mLibusbPollThread;
  void usbPollThreadFunc();
};

#endif  // USBDEVICEMANAGER_H
