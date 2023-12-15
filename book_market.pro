TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    book.cpp \
    customer.cpp \
    employee.cpp \
    invoice.cpp \
    user.cpp \
    book_system.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    book_system.h \
    book.h \
    customer.h \
    employee.h \
    user.h \
    invoice.h

