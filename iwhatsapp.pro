#-------------------------------------------------
#
# Project created by QtCreator 2017-06-06T23:56:10
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += console c++11

TARGET = iwhatsapp
TEMPLATE = app

LIBS += -lmysqlcppconn

SOURCES += main.cpp\
        widget.cpp \
    grupos.cpp \
    user.cpp \
    usermanager.cpp \
    cadastro.cpp \
    conversas.cpp \
    conversa.cpp \
    cadconversas.cpp \
    message.cpp \
    adduser.cpp

HEADERS  += widget.h \
    grupos.h \
    user.h \
    usermanager.h \
    cadastro.h \
    conversas.h \
    conversa.h \
    cadconversas.h \
    message.h \
    adduser.h \
    icons.h

FORMS    += widget.ui \
    grupos.ui \
    cadastro.ui \
    conversa.ui \
    cadconversas.ui \
    adduser.ui

RESOURCES += \
    resource.qrc

RC_FILE += myapp.rc
