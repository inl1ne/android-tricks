#include "UsbDeviceManager.h"

UsbDeviceManager::UsbDeviceManager()
  : mContext(0) {

}

UsbDeviceManager::~UsbDeviceManager() {
  if (mContext != 0) {
    libusb_exit(mContext);
    mContext = 0;
  }
}

int UsbDeviceManager::initialize() {
  if (mContext) {
    return E_ALREADYINITIALIZED;
  }
  libusb_init(&mContext);
  return OK;
}
