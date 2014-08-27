TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    template_impl.c

CONFIG(debug, debug|release):{OBJECTS_DIR = $$PWD/../build/integra/debug/obj}
else:{OBJECTS_DIR = $$PWD/../build/integra/release/obj}
RCC_DIR = $$PWD/../build/integra/rcc
UI_DIR = $$PWD/../build/integra/ui
MOC_DIR = $$PWD/../build/integra/moc
DESTDIR = $$PWD/../app

INCLUDEPATH += /usr/include/python2.7

OTHER_FILES += \
    setup.py \
    template.c \
    package/template_module/__init__.py

HEADERS += \
    template_impl.h



