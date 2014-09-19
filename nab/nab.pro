TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    UsbDeviceManager.cpp \
    UsbDevice.cpp

HEADERS += \
    UsbDeviceManager.h \
    UsbDevice.h


unix: CONFIG += link_pkgconfig
unix: PKGCONFIG += libusb-1.0

OTHER_FILES += \
    astylerc
