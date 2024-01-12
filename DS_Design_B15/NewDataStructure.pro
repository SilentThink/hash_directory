QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

DESTDIR = $$PWD/../bin
TARGET = NewDataStructure
TEMPLATE = app

SOURCES += \
    StartWidget.cpp \
    main.cpp \
    hush.cpp \
    mypushbutton.cpp \
    choosedatastructure.cpp \
    mainwindow.cpp

HEADERS += \
    StartWidget.h \
    hush.h \
    mypushbutton.h \
    choosedatastructure.h \
    mainwindow.h

FORMS += \
    StartWidget.ui \
    mainwindow.ui

RESOURCES += \
    res.qrc
