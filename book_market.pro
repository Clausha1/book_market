TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    book.cpp \
    invoice.cpp \
    book_system.cpp \
    userinterface.cpp \
    employeeinterface.cpp \
    customerinterface.cpp \
    user.cpp \
    moderinterface.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    book_system.h \
    book.h \
    invoice.h \
    userinterface.h \
    customerinterface.h \
    employeeinterface.h \
    user.h \
    moderinterface.h

