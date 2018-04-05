#-------------------------------------------------
#
# Project created by QtCreator 2018-03-28T01:29:11
#
#-------------------------------------------------

QT       += core gui sql widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Campus-in-out
TEMPLATE = app


SOURCES += main.cpp\
    account_handler.cpp \
    ui.cpp \
    institute.cpp \
    person.cpp \
    institute_member.cpp \
    security.cpp \
    database_handler.cpp \
    student.cpp \
    worker.cpp \
    faculty.cpp \
    admin.cpp

HEADERS  += \
    account_handler.h \
    ui.h \
    institute.h \
    person.h \
    institute_member.h \
    security.h \
    database_handler.h \
    student.h \
    worker.h \
    faculty.h \
    admin.h

FORMS    += mainwindow.ui \
    ui.ui \
    institute.ui \
    security.ui \
    admin.ui
