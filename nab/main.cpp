#include "UsbDeviceManager.h"

#include <iostream>
using namespace std;

int main() {
  UsbDeviceManager deviceManager;
  deviceManager.initialize();
  deviceManager.enumerateAvailableDevices(
        [](const libusb_device_descriptor& desc, const libusb_config_descriptor& config){
    cout << hex << desc.idVendor << ":" << desc.idProduct << std::endl;
    return true;
  });
  cout << "Hello, World!" << endl;
  return 0;
}
