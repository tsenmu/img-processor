#-------------------------------------------------
#
# Project created by QtCreator 2012-05-24T23:43:18
#
#-------------------------------------------------

QT       += core gui

TARGET = ImageProcessor
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    multiimagewidget.cpp \
    commentedimage.cpp \
    multiimagescrollarea.cpp \
    imagewidget.cpp \
    functionwidget.cpp \
    functionitem.cpp \
    functionpool.cpp \
    homomorphicfilterdialog.cpp \
    brightnessnormalizationdialog.cpp

HEADERS  += mainwindow.h \
    multiimagewidget.h \
    commentedimage.h \
    multiimagescrollarea.h \
    imagewidget.h \
    functionwidget.h \
    functionitem.h \
    functionpool.h \
    homomorphicfilterdialog.h \
    brightnessnormalizationdialog.h

FORMS    += mainwindow.ui \
    multiimagewidget.ui \
    commentedimage.ui \
    functionwidget.ui \
    homomorphicfilterdialog.ui \
    brightnessnormalizationdialog.ui

RESOURCES += \
    resource.qrc

OTHER_FILES += \
    myapp.rc \
    ImageProcessor.ico

RC_FILE = myapp.rc
