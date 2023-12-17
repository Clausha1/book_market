TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    book.cpp \
    invoice.cpp \
    book_system.cpp \
    customerinterface.cpp \
    employeeinterface.cpp \
    userinterface.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    book_system.h \
    book.h \
    user.h \
    invoice.h \
    customerinterface.h \
    employeeinterface.h

