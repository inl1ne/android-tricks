TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += thread debug

QMAKE_CXXFLAGS += -std=c++11 -O0

SOURCES += main.cpp \
    UsbDeviceManager.cpp \
    UsbDevice.cpp \
    utils/BackgroundThread.cpp

HEADERS += \
    UsbDeviceManager.h \
    UsbDevice.h \
    utils/BackgroundThread.h


unix: CONFIG += link_pkgconfig
unix: PKGCONFIG += libusb-1.0

OTHER_FILES += \
    astylerc
