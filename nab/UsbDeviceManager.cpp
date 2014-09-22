#include "UsbDeviceManager.h"


UsbDeviceManager::UsbDeviceManager()
  : mContext(0){

}

UsbDeviceManager::~UsbDeviceManager() {
  if (mContext != 0) {
    libusb_exit(mContext);
    mContext = 0;
  }
}

int UsbDeviceManager::initialize() {
  int result = OK;
  if (mContext) {
    return E_ALREADYINITIALIZED;
  }

  result = libusb_init(&mContext);
  return result;
}

int UsbDeviceManager::enumerateAvailableDevices(
    const enumerationcallback_t& cb) {
  void** device_list;
  int result = OK;

  ssize_t count = libusb_get_device_list(mContext, (libusb_device***)&device_list);
  if (count <= 0) {
    result = count;
  } else {
    libusb_device_descriptor desc;
    libusb_config_descriptor* config;
    bool keepGoing = true;
    void** current = device_list;
    while (*current && keepGoing) {
      libusb_get_device_descriptor((libusb_device*)*current, &desc);
      libusb_get_active_config_descriptor((libusb_device*)*current, &config);
      keepGoing = cb(desc, *config);
      libusb_free_config_descriptor(config);
      ++current;
    }
    libusb_free_device_list((libusb_device**)device_list, 1);
  }

  return result;
}



void UsbDeviceManager::usbPollThreadFunc()
{
  libusb_handle_events(mContext);
}

